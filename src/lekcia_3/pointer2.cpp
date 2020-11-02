
#include <stdio.h>

/**
 * Pole a pointery su velmi podobne.
 * int data[10];        // pole
 * int* p = data;       // adresa na zaciatok pola data
 *
 * *p       == data[0]      // p ukazuje na adresu prveho elementu v poli data
 * p+1      == &data[1]     // ked zvysime adresu p, dostaneme sa na adresu druheho elementu
 * *(p+1)   == data[1]
 */

void print_pole(int* zaciatok) {
    for (int i = 0; i < 100; i++) {
        printf("%p %d\n", &zaciatok[i], zaciatok[i]);
    }
}

void init_pole(int* zaciatok) {
    for (int i = 0; i < 100; i++) {
        *zaciatok = 0;
        zaciatok += 1;
    }
}

/**
 * Text je to iste ako pole charov.
 * char text[] = "ahoj ajtyvit";
 *
 * Textove pole musi byt ukoncene znakom '\0' (s numberickou hodnotou 0)
 * sizeof("0123456789") == 11   // posledny znak '\0' je pridany automaticky
 */

void print_char(char* zaciatok) {
    for (int i = 0; zaciatok[i] != '\0'; i++) {
        printf("pozicia %d: %c\n", i, zaciatok[i]);
    }
}

int main() {
    int data[100];

    init_pole(data);

    char text[] = "0123456789cdsasdavfdab";
    printf("velkost textu %d\n", sizeof(text));
    print_char(text);

    printf("velkost %d %d %d %d\n", sizeof(int), sizeof(char), sizeof(int*), sizeof(char*));
}
