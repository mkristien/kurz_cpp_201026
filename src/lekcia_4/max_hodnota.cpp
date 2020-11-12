#include <stdio.h>
#include <stdlib.h>

void inicializuj(int* pole, int velkost) {
  // dopln tu, inicializuj pole nahodnymi cislami
  for (int i=0; i<velkost; i++) {
    pole[i] = rand();
  }
}

int* najdi_maximum(int* pole, int velkost) {
  // dopln tu, vrat adresu na ktorej sa nachadza najvacsia hodnota v poli

  // mozeme zacat porovnavat vsetky hodnoty v poli s tou prvou
  int max_hodnota = pole[0];
  int* max_adresa = pole;
  for (int i=0; i<velkost; i++, pole++) {
    if (max_hodnota < *pole) {
      // ak sme nasli vacsiou hodnotu, zacneme porovnavat s nou
      max_hodnota = *pole;
      max_adresa  = pole;
    }
  }

  return max_adresa;
}

int main() {
  int velkost;

  scanf("%d", &velkost);

  int* pole;

  pole = (int*) malloc (velkost * sizeof(int));

  inicializuj(pole, velkost);

  int* adresa_max = najdi_maximum(pole, velkost);

  printf("najvacsia hodnota v poli je %d, na pozicii %ld, na adrese %p\n"
          , *adresa_max
          , (long int)(adresa_max-pole)
          , adresa_max);
}