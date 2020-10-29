
#include <stdio.h>
#include <stdlib.h>


int data[500];

void vygeneruj(int limit) {
    for (int i=0; i < 500; i = i+1) {
        /**
         * Funkcia rand() vygeneruje nahodne cislo od 0 po RAND_MAX
         * 
         * Ak chceme aby nahodne cislo bolo v mensom intervaly,
         * mozeme ho upravit tak, ze si z cisla nechame iba
         * zvysok po deleni nahodneho cisla hornou hranicou intervalu,
         * v ktorom chceme aby sa vysledne cislo nachadzalo.
         * 
         * e.g.:
         * 456211       % 100 -> 11
         * 1236541679   % 100 -> 79
         * 4            % 100 -> 4
         * 56           % 100 -> 56
         */
        data[i] = rand() % limit;
    }
}

int spolu() {
    /**
     * Aby sme spocitali vsetky hodnoty v poli data,
     * jednotlive hodnoty budeme postupne pridavat to
     * premennej vysledok.
     */
    int vysledok = 0;
    for (int i=0; i < 500; i = i+1) {
        vysledok = vysledok + data[i];
    }

    return vysledok;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Uzivatelka musi zadat hornu hranicu pre nahodne generovane cisla\n"
               "pouzitie:\n"
               "%s 100\n",
               argv[0]
        );
        return 1;
    }
    int limit = std::atoi(argv[1]);

    vygeneruj(limit);

    int sucet_pola = spolu();
    printf("sucet pola je %d\n", sucet_pola);
}