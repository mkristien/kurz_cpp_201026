# Operácie s textom

Text je to isté ako pole charov (`char text[]` alebo `char* text`).
Preto sa pri manipulácií s textom mozeme veľa naučiť o poliach a pointeroch.

Jednotlivé znaky sa dajú zameniť na číselné hodnoty a späť pomocou [ASCII tabulky](http://www.asciitable.com/).

## Moje ATOI
Funkcia `atoi` (ascii-to-integer) vie z textovej reprezentácie vrátiť číslo. Skús napísať vlastný kód pre túto funkciu.

```
"123"       -> 123  // toto sme robili v lekcii š
"-1"        -> -1   // treba skontrolovat znamieko
"00052"     -> 52   // odignoruj nuly na zaciatku
"  -005"    -> -5   // odignoruj medzery v nuly na zaciatku, skontroluj znamienko
"cdsa4616"  -> 0    // ak text nezacina ako cislo, vrat 0
```

## Moje ITOA
Čo tak skúsiť konvertovať čísla na text? (integer-to-ascii)
```
123 -> "123"
-15 -> "-15"
```

Môžeš začať s takýmto kódom.
```cpp
#include <stdio.h>

char int_to_char(int cislo) {
    // dopln tu
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
    // dopln tu
}

int main() {
    char text[20];

    int cislo = 54;
    moje_itoa(cislo, text);
    printf("cislo %d v texte je %s\n", cislo, text);
}
```

## Odzadu do predu
Skús prehodit znaky v texte.
```
"abcd"      -> "dcba"
"123456789" -> "987654321"
```
Môžeš začať s týmto kódom.
```cpp
#include <stdio.h>

// Mozes predpokladat, ze velkost pola opacny_text je taka ista ako text
void opacne(char* text, char* opacny_text) {
    // dopln tu
}

int main() {
    char text[] = "abcd";
    char txet[sizeof(text)];

    printf("povodne %s, opacne %s\n", text);
}
```

### Alternatíva
Prehoď znaky v texte v ramci toho istého textového poľa.
```cpp
// parameter text je zaroven aj vstup aj vysledok
void opacne(char* text);
```