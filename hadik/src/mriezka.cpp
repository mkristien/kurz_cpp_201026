
#include "mriezka.h"

#include <stdio.h>
#include <stdlib.h>

#include "config.h"

meta_mriezka data_mriezka;

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
 * Vytvor mriezku na zaciatku hry
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

void vytvor_potravu(meta_mriezka* m) {
  while (true) {
    int x = rand() % m->stlpce; // (*m).stlpce
    int y = rand() % m->riadky;

    if (m->mriezka[y][x] == MRIEZKA_PRAZDNA) {
      m->mriezka[y][x] = MRIEZKA_POTRAVA;
      break;
    }
  }
}

int mriezka_je_plna(meta_mriezka* m) {
  for (int i=0; i < m->riadky; i++) {
    for (int j=0; j < m->stlpce; j++) {
      if (m->mriezka[i][j] == MRIEZKA_PRAZDNA) {
        return 0;
      }
    }
  }

  return 1;
}
