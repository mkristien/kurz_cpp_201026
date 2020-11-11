#include <stdio.h>
#include <stdlib.h>

#include "config.h"

// nove datove typy
struct bod {
  int x;  // stlpec
  int y;  // riadok
};
enum smer { dolava, doprava, dole, hore, ziaden};

// datove premenne v statickom priestore
char  mriezka[RIADKY][STLPCE];

bod   had[STLPCE*RIADKY];
int   had_dlzka;
smer  had_smer;

/**
 * Vytvor hada na zaciatku hry
 */
void init_had() {
  had[0].x = 1;
  had[0].y = 1;

  had[1] = {2, 1};
  had[2] = {3, 1};
  had[3] = {4, 1};
  had[4] = {5, 1};

  had_dlzka = 5;
  had_smer  = doprava;
}

/**
 * Zobraz data z hada v mriezke
 */
void had_do_mriezky() {
  // telo
  for (int i=0; i<had_dlzka-1; i++) {
    bod pozicia = had[i];
    mriezka[pozicia.y][pozicia.x] = 'X';
  }

  // hlava
  bod hlava = had[had_dlzka-1];
  mriezka[hlava.y][hlava.x] = 'O';
}

/**
 * Zmen data o hadovi podla toho, ktorym smerom sa hybe
 */
void had_pohyb(smer novy_smer) {
  // poloha novej hlavy sa posunie o 1 urcitym smerom od povodnej hlavy
  bod nova_hlava = had[had_dlzka-1];

  // ak sa smer nemeni, pouzi povodny smer
  if (novy_smer == ziaden) {
    novy_smer = had_smer;
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

  had_smer        = novy_smer;
  had[had_dlzka]  = nova_hlava;
  // vymaz chvost z hada
  for (int i=0; i<had_dlzka; i++) {
    had[i] = had[i+1];
  }
}

/**
 * ------------------
 * |XXXX@           |
 * |                |
 * |                |
 * ------------------
 */
void init_mriezka() {
  // prvy riadok
  for (int i=0; i < STLPCE; i++) {
    mriezka[0][i] = '-';
  }

  // stredne riadky
  for (int i=1; i<RIADKY-1; i++) {
    // prvy stlpec
    mriezka[i][0] = '|';
    // stredne stlpce
    for (int j=1; j<STLPCE-1; j++) {
      mriezka[i][j] = ' ';
    }
    // posledny stlpec
    mriezka[i][STLPCE-1] = '|';
  }

  // posledny riadok
  for (int i=0; i < STLPCE; i++) {
    mriezka[RIADKY-1][i] = '-';
  }
}

void print_mriezka() {
  printf("\e[2J\e[H");    // vycisti terminal a daj kurzor na poziciu 0,0

  for (int i=0; i<RIADKY; i++) {
    for (int j=0; j<STLPCE; j++) {
      putchar(mriezka[i][j]);   // printf("%c", char)
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
    case 'i':
      return hore;
    case 'j':
      return dolava;
    case 'k':
      return dole;
    case 'l':
      return doprava;
    default:
      return ziaden;
  }
}

int main() {
  init_mriezka();
  init_had();
  had_do_mriezky();
  print_mriezka();

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
    if (klavesa == 'q') {
      break;
    }

    // 2
    smer novy_smer = klavesa_na_smer(klavesa);

    // 3
    had_pohyb(novy_smer);

    // 4
    init_mriezka();
    had_do_mriezky();
    print_mriezka();
  }

  // obnov povodne nastevenie terminalu
  system("stty sane");
}
