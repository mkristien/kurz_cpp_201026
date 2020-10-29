
/**
 * ./nasobky 5
 * vystup:
 * 5 * 1 = 5
 * 5 * 2 = 10
 * 5 * 3 = 15
 * 5 * 4 = 20
 * 5 * 5 = 25
 *
 * ./nasobky 6
 * vystup:
 * 6 * 1 = 6
 * 6 * 2 = 12
 * 6 * 3 = 18
 * 6 * 4 = 24
 * 6 * 5 = 30
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int hodnota = std::atoi(argv[1]);

    for (int i = 1; i <= 5 ; i = i + 1) {
        int vysledok = hodnota * i;
        printf("%d * %d = %i\n", hodnota, i, vysledok);
    }
}