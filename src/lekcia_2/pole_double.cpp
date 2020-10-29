
#include <stdio.h>
#include <stdlib.h>


double data[500];

void vygeneruj(double limit) {
    for (int i=0; i < 500; i = i+1) {
        /**
         * Funkcia rand() vygeneruje nahodne cislo od 0 po RAND_MAX
         *
         * Ak chceme vygenerovat desatinne cisla, stale mozeme zacat s celym nahodnym cislom.
         * Ako prve premenime cele nahodne cislo na desatinne:
         * (double) rand()
         *
         * Potom cislo upravime tak, aby bolo v intervale od 0 po 1:
         * (double) rand() / RAND_MAX
         *
         * Aby sme interval (0,1) upravili na (0, limit), staci nam cislo vynasobit premennou limit
         * limit * (double) rand() / RAND_MAX
         */
        data[i] = limit * (double) rand() / RAND_MAX ;
    }
}

double spolu() {
    double vysledok = 0;
    for (int i=0; i < 500; i = i+1) {
        vysledok = vysledok + data[i];
    }

    return vysledok;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Uzivatelka musi zadat hornu hranicu pre nahodne generovane cisla\n"
               "pouzitie:\n"
               "%s 10.5\n",
               argv[0]
        );
        return 1;
    }
    double limit = std::atof(argv[1]);

    vygeneruj(limit);

    double sucet_pola = spolu();
    printf("sucet pola je %f\n", sucet_pola);
}