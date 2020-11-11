#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#include "config.h"
#include "datove_typy.h"
#include "had.h"
#include "mriezka.h"
#include "zrazky.h"

/**
 * Tato funkcia sa zavola vzdy ked zazvoni budik.
 *
 * V ramci tejto funkcie sa hned nastavi dalsi budik.
 */
void alarm(int signal) {
   static struct itimerval val;
   val.it_value.tv_sec  = 0;
   val.it_value.tv_usec = 500000;

   setitimer (ITIMER_REAL, &val, NULL);
}

/**
 * Tato funkcia zaregistruje funkciu alarm(), aby sa funkcia alarm()
 * spustila vzdy ked zazvoni budik.
 */
void nastav_alarm() {
   struct sigaction action  = {};
   action.sa_handler        = alarm;

   sigaction(SIGALRM, &action, NULL);
}

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
  vytvor_potravu(m);
  print_mriezka(m);

  nastav_alarm();   // zaregistruj funkciu budika
  alarm(0);         // zapni prvy budik

  // nastav terminal tak, aby sa klavesy:
  // - dostali do vstupu hned (nie az po stlaceni ENTER)
  // - nezobrazovali v terminali
  system("stty cbreak -echo");

  /**
   * Hra reaguje na stlacenie klavesy:
   * 1. nacitaj stlacenu klavesu
   * 2. vypocitaj novy smer na zaklade klavesy
   * 3. posun hada podla noveho smeru
   * 4. detekcia zrazok
   * 5. zobraz mriezku s novymi udajmi
   */
  char klavesa;
  while (true) {
    // 1
    klavesa = getchar();
    alarm(0);   // nastav dalsi budik
    if (klavesa == KLAVESA_EXIT) {
      break;
    }

    // 2
    smer novy_smer = klavesa_na_smer(klavesa);

    // 3
    had_pohyb(h, novy_smer);

    // 4
    if (zrazka_potrava(m, h)) {
      had_sa_najedol(h);
      had_do_mriezky(h, m->mriezka);

      if (mriezka_je_plna(m)) {
        printf("had vyhral, koniec hry\n");
        break;
      }

      vytvor_potravu(m);
    } else if (zrazka_had(m, h) || zrazka_stena(m, h)) {
      printf("nastala zrazka, koniec hry\n");
      break;
    } else {
      had_do_mriezky(h, m->mriezka);
    }

    // 5
    print_mriezka(m);
  }

  // obnov povodne nastevenie terminalu
  system("stty sane");
}
