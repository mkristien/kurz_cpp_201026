
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    char retazec[] = "Dobry den";
    printf("Ahoj AjTyvIT, %s\n", retazec);

    printf("pocet argumentov %d\n", argc);

    // printf("prvy argument je %s\n", argv[0]);
    // if (argc >= 2) {
    //     printf("druhy argument je %s\n", argv[1]);
    // }
    // if (argc >= 3) {
    //     printf("treti argument je %s\n", argv[2]);
    // }

    /**
     * S pouzitim for cyklu mozeme vykonat prikazy jednotlivo pre kazdy argument.
     *
     * Najskor vystvorime premennu i, a nastavime jej pociatocnu hodnotu na 0.
     * Potom skontrolujeme podmienku "i < argc", ak je pravdiva, vstupime do tela
     * for cyklu. Po vykonani tela cyklu, zvysime hodnotu v premennej i (i = i+1).
     * Takto pokracujeme, pokial "i < argc".
     */
    for (int i = 0; i < argc ; i = i+1) {
        printf("argument na pozicii %d, je %s\n", i, argv[i]);
    }
}
