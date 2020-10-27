
#include <stdio.h>

int main () {
    printf("Zadaj cislo: ");

    // deklarujeme premennu a nacitame do nej input od uzivatelky
    int cislo;
    scanf("%i", &cislo);

    printf("Zadane cislo je: %i\n", cislo);
    
    /**
     * Zmena toku programu:
     * V zavyslosti od vyhodnotenia podmienky "cislo % 2 == 0"
     * (i.e. zvysok po deleni cisla dvomi sa rovna nule?),
     * program vykona bud funkciu
     *      printf("je to parne");
     * alebo
     *      printf("je to neparne");
     */
    if (cislo % 2 == 0) {
        printf("je to parne");
    } else {
        printf("je to neparne");
    }
    return 0;
}
