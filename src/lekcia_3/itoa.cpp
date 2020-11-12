#include <stdio.h>

char int_to_char(int cislo) {
    if (cislo < 0 || cislo >= 10) {
        return -1;
    }
    return '0' + cislo;
}

/**
 * input:   cislo       - integer ktory sa snazime zmenit na text
 * output:  vysledok    - output pointer na pole charov, kde mozeme
 *                        zapisat vysledny text
 *
 * Mozes predpokladat, ze pole vysledok ma dostatok miesta na vsetky
 * znaky potrebne na vypisanie hodnoty cisla.
 * Nezabudni pridat '\0' na koniec.
 */
void moje_itoa(int cislo, char* vysledok) {
    if (cislo < 0) {
        *vysledok = '-';
        vysledok++;
        cislo *= -1;    // zvysok kodu bude pracovat s kladnym cislom
    }

    char* zaciatok = vysledok;

    *vysledok = '0';
    while (cislo != 0) {
        *vysledok = int_to_char(cislo % 10);
        cislo /= 10;
        vysledok++;
    }
    *vysledok = '\0';

    int dlzka = vysledok - zaciatok;
    // prehost hodnoty v textovom poli, zacni s prehodenim prveho a posledneho
    // pismena a potom sa posun o i do stredu
    for (int i = 0; i < dlzka / 2 ; i++) {
        char c = zaciatok[i];
        zaciatok[i] = zaciatok[(dlzka-1) - i];
        zaciatok[dlzka -1 - i] = c;
    }
}

int main() {
    char text[20];
    int  cislo;

    cislo = -541;
    moje_itoa(cislo, text);
    printf("cislo %d v texte je %s\n", cislo, text);

    cislo = -15;
    moje_itoa(cislo, text);
    printf("cislo %d v texte je %s\n", cislo, text);
}