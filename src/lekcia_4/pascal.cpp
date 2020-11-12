#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
  int riadky = 10;
  if (argc >= 2) {
    riadky = std::atoi(argv[1]);
  }

  int** pascal;

  // vytvor pole riadov
  pascal = (int**) malloc(riadky * sizeof(int*));
  // vytvor jednotlive riadky
  for (int i=0; i<riadky; i++) {
    // dlzka kazdeho riadku koresponduje s jeho poziciou/vyskou i
    pascal[i] = (int*) malloc((i+1)*sizeof(int));
  }

  // inicializuj trojuholnik
  // prvy riadok je iba 1
  pascal[0][0] = 1;

  // ostatne riadky inicializujeme podla velkosti
  for (int riadok=1; riadok < riadky; riadok++) {
    // prva pozicia v riadku je vzdy 1
    pascal[riadok][0] = 1;

    // stredne pozicie su suctom hodnot v hodnom riadku
    for (int i=1; i < riadok+1; i++) {
      pascal[riadok][i] = pascal[riadok-1][i-1] + pascal[riadok-1][i];
    }

    // posledna pozicia v riadku je vzdy 1
    pascal[riadok][riadok] = 1;
  }

  // print pascalov trojuholnik, a spocitaj vsetky hodnoty
  int sucet = 0;
  for (int riadok=0; riadok < riadky; riadok++) {
    for (int i=0; i < riadok+1; i++) {
      printf("%d ", pascal[riadok][i]);
      sucet += pascal[riadok][i];
    }
    printf("\n");
  }

  printf("sucet vsetky hodnout v trojuholniku je %d\n", sucet);
}

