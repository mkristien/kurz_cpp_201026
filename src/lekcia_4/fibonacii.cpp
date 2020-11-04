
#include <stdio.h>
#include <stdlib.h>
/**
 * definicia:
 * F(x) = F(x-1) + F(x-2)
 *
 * F(0) = 0
 * F(1) = 1
 */
int fibonacii(int x) {
    if (x <= 1) {
        return x;
    }

    return fibonacii(x-1) + fibonacii(x-2);
}

int main(int argc, char* argv[]) {
    int cislo = std::atoi(argv[1]);

    for (int i = 0; i < cislo; i++) {
        printf("fibonaci %d je %d\n", i, fibonacii(i));
    }
}

