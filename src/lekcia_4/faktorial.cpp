
#include <stdio.h>
#include <stdlib.h>

/**
 * f(x) = x * (x-1) * (x-2) ... * 1
 * f(3) = 3 * 2 * 1 = 6
 * f(5) = 5 * 4 * 3 * 2 * 1 = 120
 */

int faktorial(int x) {
    if (x == 1) {
        return 1;
    }

    return x * faktorial(x-1);
}

int faktorial_cyklus(int x) {
    int vysledok = 1;
    while (x > 1) {
        vysledok *= x;      // vysledok = vysledok * x;
        x--;                // x = x - 1
    }

    return vysledok;
}

int main(int argc, char* argv[]) {
    int cislo = std::atoi(argv[1]);

    int a = faktorial(cislo);
    int b = faktorial_cyklus(cislo);
    printf("faktorial cisla %d je %d %d\n", cislo, a, b);
}