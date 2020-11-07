# Úlohy po lekcií 4

## Fibonacii
Na hodine sme si predstavili rekurzívne funkcie, a ako sa dajú použiť na vypočínanie (fibonacii)[https://sk.wikipedia.org/wiki/Fibonacciho_postupnos%C5%A5] čísla.

Skús prepísať kód z hodiny tak, aby sa fibonacii číslo počítalo bez rekurzie. Namiesto rekuzie, skús použiť `for` cyklus.

## Nájdi najvačšiu hodnotu
Toto zadanie kombinuje prácu s adresamy a s dynamickou pamäťou (heap/halda). Program by mal:

1. Opýtať sa používateľky na veľkosť poľa.
2. Vytvoriť pole `int` podľa zadanej veľkosti s použitím `malloc`.
3. Inicialozovať pole náhodnými číslami bez použitia syntaxu poľa `[]`
4. Nájsť najväčšiu hodnotu v poli a vrátiť adresu, kde sa táto hodnota nachádza.

```cpp
#include <stdio.h>
#include <stdlib.h>

void inicializuj(int* pole, int velkost) {
    // dopln tu, inicializuj pole nahodnymi cislami
}

int* najdi_maximum(int* pole, int velkost) {
    // dopln tu, vrat adresu na ktorej sa nachadza najvacsia hodnota v poli
}

int main() {
    int velkost;

    // dopln tu, nacitaj velkost pola z terminalu

    int* pole;

    // dopln tu, vytvor pole

    inicializuj(pole, velkost);

    int* adresa_max = najdi_maximum(pole, velkost);

    printf("najvacsia hodnota v poli je %d, na pozicii %ld, na adrese %p\n"
            , *adresa_max
            , (long int)(adresa_max-pole)
            , adresa_max);
}

```

## Dynamický pascalov trojuholník
[Pascalov trojuholník](https://sk.wikipedia.org/wiki/Pascalov_trojuholn%C3%ADk) je jednoduchá pravideľná štruktúra v matematike. Trojuholník začína na vrchole s jednou hodnotou a každý ďalši riadok má o jednu hodnotu viac (1, 2, 3, 4, ...) až do nekonečna. Všetky pozície na okraji trojuholníka majú hodnotu 1. Pozície v strede majú hodnotu súčtu dvoch pozícii priamo nad danou pozíciou.
```
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1
...
```
Vytvor takúto štruktúru (skoro ako tabuľka) dynamicky s použitím `malloc`. Užívateľka by mala zadať hĺbku trojuholníka (počet riadov) v terminály.

Po vytvorení trojuholníka môžeš skúsiť spočítať všetky jeho hodnoty.
