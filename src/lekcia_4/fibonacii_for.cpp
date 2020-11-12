
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
  if (x < 2) return x;

  int a = 0;    // pred-predchadzajuce cislo
  int b = 1;    // predchadzajuce cislo

  int vysledok;
  for (int i=1; i<x; i++) {
    vysledok = a + b;

    // posun hodnoty a, b
    a = b;
    b = vysledok;
  }

  return vysledok;
}

int main(int argc, char* argv[]) {
    int cislo = std::atoi(argv[1]);

    for (int i = 0; i < cislo; i++) {
        printf("fibonaci %d je %d\n", i, fibonacii(i));
    }
}

