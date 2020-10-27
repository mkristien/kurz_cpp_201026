# C++
Každý C++ program musí mať funkciu `main`. Táto funkcia slúži ako vstupný bod, tam kde tok programu začne pri spustení aplikácie. Najmenší program v C++ teda môže vyzerať asi takto.
```
int main() {}
```
## Input/Output
Aby náš program aj niečo robil, musíme napísať trochu viac kódu. Najzákladnejšie operácie sú input a output. Outputom nám program niečo povie do terminálu. Input slúži na to, aby užívateľka mohla povedať niečo programu.

V C++ možeme nájsť funkcie inputut a outputu v knižnici `stdio.h`.
```cpp
#include <stdio.h>
int main() {}
```

Na output sa používa funkcia `printf`. Do tejto funkcie môžeme napísať output text priamo (použitím "text"), alebo do textu môžeme zahrnúť hodnoty z nejakej premennej. Ak chceme aby output text obsahoval nový riadok, stačí pridať `\n`.
```cpp
#include <stdio.h>
int main() {
    printf("Ahoj v AjTyvIT\n");     // output text

    // premenna typu integer (cele cislo)
    int premenna = 5;

    // V texte zadame poziciu, kde sa ma hodnota z premennej zobrazit
    // pomocou %d (ako decimal), alebo %i (ako integer)
    printf("Moja hodnota je %d, to je celkom malo\n", premenna);

    int cislo = -10;
    printf("Teraz mam dve cisla: %d a %d, ktore je vacsie?\n", premenna, cislo);
}
```

Na input od užívateľky používame funkciu `scanf`. Tá vyzerá podobne ako `printf`, akurát vždy musíme špecifikovať do ktorej premennej sa má input načítať.
```cpp
#include <stdio.h>
int main() {
    printf("Ahoj v AjTyvIT\nZadaj hodnotu\n");     // output text

    // premenna typu integer (cele cislo)
    int premenna;
    scanf("%d", &premenna);     // nacitaj input od uzivatelky
    printf("Zadana hodnota je %d\n", premenna);
}
```

## Tok Programu
Typicky program vykonáva riadok za riadkom. Aby sme však mohli zmeniť správanie programu v závyslosti od inputu, musíme byť schopné zmeniť tok programu.

### If/Else
Štruktúra `if` nám dovoluje opýtať sa programu, či je určitá podmienka pravdivá. Ak áno, program vykoná príkazy v časti `if`. Ak nie, program vykoná príkazy v časti `else`. Čast `else` je nepovinná a ak chýba, program bude ďalej pokračovať.

```cpp
if (<podmienka>) {
    <prikazy ak je podmienka pravdiva>
} else {
    <prikazy ak je podmienka nepravdiva>
}

```cpp
#include <stdio.h>
int main() {
    printf("Zadaj hodnotu\n");
    int premenna;
    scanf("%d", &premenna);

    // ak je premenna parna
    if (premenna % 2 == 0) {
        printf("cislo je parne\n");
    } else {
        printf("cislo je neparne\n");
    }
}
```