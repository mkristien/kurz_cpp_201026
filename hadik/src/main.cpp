#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "config.h"
#include "datove_typy.h"
#include "had.h"
#include "mriezka.h"

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
