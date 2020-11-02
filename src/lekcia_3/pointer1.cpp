

#include <stdio.h>
#include <stdlib.h>

/**
 * Funkcia foo() pouziva "output pointer", i.e. namiesto toho,
 * aby nahodnu hodnotu vratila z pouzitim "return" ju zapise
 * priamo na adresu zadanu v argumente funkcie
 */
void foo(int* p) {
    *p = rand();
}

/**
 * Pointer je adresa v pamati aplikacie, kde sa nachadza nejaka premenna.
 *
 * int a;           // premenna v pamati aplikacie
 * int* b = &a;     // b uchovava adresu na ktorej je premenna a
 * *b = 10;         // na miesto kam ukazuje adresa b sa zapise hodnota 10
 *                  // tym padom sa do premennej a zapise 10
 */
int main() {
    int a = 5;

    printf("premenna a, hodnota: %d, adresa: %p\n", a, &a);

    int  b = a;
    int* c = &a;
    printf("adresa c %p s hodnotou %d\n", c, *c);

    a += 1;     // akoby a = a+1

    printf("premenna a %d\n");
    printf("b %d, *c %d\n", b, *c);

    foo(c);
    printf("b %d, *c %d, %d\n", b, *c, a);
}
