
#include "had.h"

#include <stdlib.h>

meta_had data_had;

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
  data_had.had[5] = {5, 1};
  data_had.had[6] = {6, 1};
  data_had.had[7] = {7, 1};

  data_had.vymazany_chvost = {6, 1};

  data_had.had_dlzka = 8;
  data_had.had_smer  = doprava;
  return &data_had;
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
 * bod B;
 * b.x = 5;
 *
 *
 * bod* C = &B;
 * C.x = 5; // nefunguje
 * (*C).x = 5;
 * C->x   = 5;
 */
void had_sa_najedol(meta_had* h) {
  for (int i=h->had_dlzka; i > 0; i--) {
    h->had[i] = h->had[i-1];
  }

  h->had[0] = h->vymazany_chvost;
  h->had_dlzka++;
}
