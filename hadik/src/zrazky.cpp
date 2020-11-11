
#include "zrazky.h"
#include "config.h"

int zrazka_potrava(meta_mriezka* m, meta_had* h) {
  bod hlava = h->had[h->had_dlzka - 1];
  if (m->mriezka[hlava.y][hlava.x] == MRIEZKA_POTRAVA) {
    return 1;
  } else {
    return 0;
  }
}

int zrazka_had(meta_mriezka* m, meta_had* h) {
  bod hlava = h->had[h->had_dlzka - 1];
  int vysledok = m->mriezka[hlava.y][hlava.x] == MRIEZKA_HAD_TELO ? 1 : 0;
  return vysledok;
}

int zrazka_stena(meta_mriezka* m, meta_had* h) {
  bod hlava = h->had[h->had_dlzka - 1];
  int vysledok = 0;
  vysledok = m->mriezka[hlava.y][hlava.x] == MRIEZKA_STENA_HORIZ ? 1 : 0;
  vysledok = vysledok || m->mriezka[hlava.y][hlava.x] == MRIEZKA_STENA_VERTI ? 1 : 0;
  return vysledok;
}
