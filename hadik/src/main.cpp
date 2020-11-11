#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "config.h"

// nove datove typy
enum smer { dolava, doprava, dole, hore, ziaden};

struct bod {
  int x;  // stlpec
  int y;  // riadok
};

struct meta_had {
  bod*  had;
  int   had_dlzka;
  smer  had_smer;
  bod   vymazany_chvost;
};

struct meta_mriezka {
  int     riadky;
  int     stlpce;
  char**  mriezka;
};

meta_had     data_had;
meta_mriezka data_mriezka;

/**
 * Vytvor hada na zaciatku hry
 */
meta_had* init_had(int max_dlzka) {
  data_had.had = (bod*) malloc(max_dlzka * sizeof(bod));
  data_had.had[0] = {1, 1};
  data_had.had[1] = {2, 1};
  data_had.had[2] = {3, 1};
  data_had.had[3] = {4, 1};
  data_had.had[4] = {5, 1};

  data_had.vymazany_chvost = {6, 1};

  data_had.had_dlzka = 5;
  data_had.had_smer  = doprava;
  return &data_had;
}

/**
 * Zobraz data z hada v mriezke
 */
void had_do_mriezky(meta_had* h, char** mriezka) {
  // zmen vymazany chvost na "prazdne" v mriezke
  mriezka[h->vymazany_chvost.y][h->vymazany_chvost.x] = MRIEZKA_PRAZDNA;

  // telo
  for (int i=0; i< h->had_dlzka -1; i++) {
    bod pozicia = h->had[i];
    mriezka[pozicia.y][pozicia.x] = MRIEZKA_HAD_TELO;
  }

  // hlava
  bod hlava = h->had[h->had_dlzka-1];
  mriezka[hlava.y][hlava.x] = MRIEZKA_HAD_HLAVA;
}

/**
 * Zmen data o hadovi podla toho, ktorym smerom sa hybe
 */
void had_pohyb(meta_had* h, smer novy_smer) {
  // poloha novej hlavy sa posunie o 1 urcitym smerom od povodnej hlavy
  int dlzka       = h->had_dlzka;
  bod nova_hlava  = h->had[dlzka-1];

  // ak sa smer nemeni, pouzi povodny smer
  if (novy_smer == ziaden) {
    novy_smer = h->had_smer;
  }

  switch (novy_smer) {
    case dolava:
      nova_hlava.x--;
      break;
    case doprava:
      nova_hlava.x++;
      break;
    case hore:
      nova_hlava.y--;
      break;
    case dole:
      nova_hlava.y++;
      break;
    default:
      break;
  }

  h->had_smer   = novy_smer;
  h->had[dlzka] = nova_hlava;
  // vymaz chvost z hada
  h->vymazany_chvost = h->had[0];
  for (int i=0; i< dlzka; i++) {
    h->had[i] = h->had[i+1];
  }
}

/**
 * ------------------
 * |XXXX@           |
 * |                |
 * |                |
 * ------------------
 */
meta_mriezka* init_mriezka(int riadky, int stlpce) {
  /**
   * mriezka
   * [0]        -> [0, 1, 3, 4, ..., stlpce-1]
   * [1]        -> [0, 1, 3, 4, ..., stlpce-1]
   * [2]        -> [0, 1, 3, 4, ..., stlpce-1]
   * [3]        -> [0, 1, 3, 4, ..., stlpce-1]
   * ...
   * [riadky-1] -> [0, 1, 3, 4, ..., stlpce-1]
   */
  char** mriezka = (char**) malloc(riadky * sizeof(char*));
  for (int i=0; i<riadky; i++) {
    mriezka[i] = (char*) malloc(stlpce*sizeof(char));
  }

  // prvy riadok
  for (int i=0; i < stlpce; i++) {
    mriezka[0][i] = MRIEZKA_STENA_HORIZ;
  }

  // stredne riadky
  for (int i=1; i<riadky-1; i++) {
    // prvy stlpec
    mriezka[i][0] = MRIEZKA_STENA_VERTI;
    // stredne stlpce
    for (int j=1; j<stlpce-1; j++) {
      mriezka[i][j] = MRIEZKA_PRAZDNA;
    }
    // posledny stlpec
    mriezka[i][stlpce-1] = MRIEZKA_STENA_VERTI;
  }

  // posledny riadok
  for (int i=0; i < stlpce; i++) {
    mriezka[riadky-1][i] = MRIEZKA_STENA_HORIZ;
  }

  data_mriezka.mriezka = mriezka;
  data_mriezka.riadky  = riadky;
  data_mriezka.stlpce  = stlpce;
  return &data_mriezka;
}

void print_mriezka(meta_mriezka* m) {
  printf("\e[2J\e[H");    // vycisti terminal a daj kurzor na poziciu 0,0

  for (int i=0; i < m->riadky; i++) {
    for (int j=0; j < m->stlpce; j++) {
      putchar(m->mriezka[i][j]);   // printf("%c", char)
    }
    putchar('\n');
  }
}

/**
 *   ^
 * < v >
 *
 *   i
 * j k l
 */
smer klavesa_na_smer(char klavesa) {
  switch (klavesa) {
    case KLAVESA_HORE:
      return hore;
    case KLAVESA_DOLAVA:
      return dolava;
    case KLAVESA_DOLE:
      return dole;
    case KLAVESA_DOPRAVA:
      return doprava;
    default:
      return ziaden;
  }
}

int main(int argc, char* argv[]) {
  int riadky, stlpce;
  if (argc == 3) {
    riadky = std::atoi(argv[1]);
    stlpce = std::atoi(argv[2]);
    if (riadky < 5  || riadky > 50 ||
        stlpce < 10 || stlpce > 200) {
      printf("riadky musia byt medzi 5-50, stlpce 10-200\n");
      printf("pouzijem predvolene hodnoty %d, %d\n", PREDVOLENE_RIADKY, PREDVOLENE_STLPCE);
      riadky = PREDVOLENE_RIADKY;
      stlpce = PREDVOLENE_STLPCE;
      sleep(2);
    }
  } else {
    printf("mozes zadat riadky a stlpce pri spusteni programu:\n");
    printf("%s <riadky> <stlpce>\n", argv[0]);
    printf("pouzijem predvolene hodnoty %d, %d\n", PREDVOLENE_RIADKY, PREDVOLENE_STLPCE);
    riadky = PREDVOLENE_RIADKY;
    stlpce = PREDVOLENE_STLPCE;
    sleep(2);
  }

  meta_mriezka* m = init_mriezka(riadky, stlpce);
  meta_had*     h = init_had(riadky*stlpce);
  had_do_mriezky(h, m->mriezka);
  print_mriezka(m);

  // nastav terminal tak, aby sa klavesy:
  // - dostali do vstupu hned (nie az po stlaceni ENTER)
  // - nezobrazovali v terminali
  system("stty cbreak -echo");

  /**
   * Hra reaguje na stlacenie klavesy:
   * 1. nacitaj stlacenu klavesu
   * 2. vypocitaj novy smer na zaklade klavesy
   * 3. posun hada podla noveho smeru
   * 4. zobraz mriezku s novymi udajmi
   */
  char klavesa;
  while (true) {
    // 1
    klavesa = getchar();
    if (klavesa == KLAVESA_EXIT) {
      break;
    }

    // 2
    smer novy_smer = klavesa_na_smer(klavesa);

    // 3
    had_pohyb(h, novy_smer);

    // 4
    had_do_mriezky(h, m->mriezka);
    print_mriezka(m);
  }

  // obnov povodne nastevenie terminalu
  system("stty sane");
}
