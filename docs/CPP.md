# C++
Každý C++ program musí mať funkciu `main`. Táto funkcia slúži ako vstupný bod, tam kde tok programu začne pri spustení aplikácie. Najmenší program v C++ teda môže vyzerať asi takto.
```
int main() {}
```
## Input/Output
Aby náš program aj niečo robil, musíme napísať trochu viac kódu. Najzákladnejšie operácie sú input a output. Outputom nám program niečo povie do terminálu. Input slúži na to, aby užívateľka mohla povedať niečo programu.

### Input/Output počas behu programu

V C++ možeme nájsť funkcie inputu a outputu v knižnici `stdio.h`.
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

### Input pri štarte programu
Zadávanie inputu pri štarte programu môže byť často jednoduchší spôsob ako ovplyvniť správanie nášho programu. Pri spúšťaní aplikácie v terminály môžeme jednoducho za názvom programu pridať ľubovoľne veľa argumentov.

```
$ ./program.exe argument1 argument2 argument3
```

Tieto argumenty môžeme v programe získať pomocou premenných `int argc` a `char* argv[]`. Premenná `argc` určuje počet zadaných argumentov. Premenná `argv` je pole reťazcov, ktoré obsahujú text zadaných argumentov.

Program má vždy aspoň jeden argument. Prvý argument je samotný názov programu.
```cpp
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
    for (int i = 0; i < argc ; i = i+1) {
        printf("argument na pozicii %d, je %s\n", i, argv[i]);
    }
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

### For cyklus
Aby sme mohli niekoľko riadkov kódu zopakovať ľubovoľný počet krát, používame `for` cyklus s takýmto syntaxom.
```cpp
for (<na zaciatku>; <podmienka>; <po kazdom cykle>) {
    <telo>
}
```
Časť `<na zaciatku>` sa vykoná iba raz, pred začatím výkonu `for` cyklu. Tu môžeme vytvoriť premenné, ktoré budu v cykle používané.

Časť `<podmienka>` sa vyhodnotí pred každým začatím cyklu. Má podobný význam ako podmienka pri štruktúre `if`. Ak sa podmienka nesplní, cyklus sa ukončí. Ak je podmienka splnená, program vykoná `<telo>` cyklu.

Po vykonaní každého cyklu sa vykoná časť `<po kazdom cykle>`. Tu môžeme upraviť rôzne premenné, najčastejšie navýšime hodnotu premennej vytvorenej v časti `<na zaciatku>`.

Takto môžeme vykonať cyklus X krát:
```cpp
#include <stdio.h>
int main() {
    for (int i=0; i < X; i = i+1) {
        printf("vykonavam cyklus cislo %d\n", i);
    }
}
```

### Funkcie
Okrem funkcie `main` a funkcií rôznych knižníc môžeme vytvárať a používať vlastne funkcie. Každá funkcie vyzerá približne takto:
```cpp
/*
<typ vysledku funckie> <nazov funkcie> (<list parametrov>) {
    <telo funkcie>
}
*/

// napr.
#include <stdlib.h>
int nahodne_cislo(int horna_hranica) {
    return rand() % horna_hranica;
}

int main() {
    int cislo = nahodne_cislo(100);
    printf("vygenerovane cislo je %d\n", cislo);
}

```
Použitím slovíčka `return`, funkcia vracia výslednú hodnotu. Zavolaním funkcie (`nahone_cislo(100)`) tok programu vstúpi do tela funkcie. Po vykonaní tela funkcie sa tok programu vráti na miesto, odkiaľ bola funkcia zavolaná.


## Dátove typy
C++ podporuje viaceré dátové typy premenných, na narábanie s celými číslami, desatinnými číslami, a textom.

### Čísla
Celé čísla môžu mať hodnotu medzi -2147483648 a 2147483647. Na vytvorenie premennej stačí povedať `int <premenna>`, napr `int i`.

Desatinné čísla, aj keď sú relatívne flexibilné, nedokážu reprezentovať všetky čísla s dokonalou presnosťou. Napríklad číslo 0,3333333... musí byť pri reprezentácií v počítači zaokrúhlené. Najčastejšie preto používame typ `double`, ktorý ma dvojnásobnú presnosť oproti typu `float`.

Vo výstupnej funkcií `printf` môžeme zadať celé číslo s použitím `%d` alebo `%i`. Desatinné číslo zadáme ako `%f`.
```cpp
int     cele      = 5;
double  desatinne = 3.14;
printf("cele cislo je %d, a desatinne cislo je %f\n", cele, desatinne);
```

### Pole
Viacero hodnôt rovnakého typu môže byť uložených v dátovom poli. Hranaté zátvorky slúžia na prístup k jednotlivým hodnotám poľa. Prvá hodnota v poli začína na pozícii 0.
```cpp
// pole mozeme vytvorit bez pociatocnych hodnout,
// alebo vytvorime pole priamo s urcitymi hodnotami
int data[5];
int udaje[] = {1, 2, 3, 4};

printf("hodnota na pozicii 2 je %d\n", udaje[2]);
```

### Reťazec - text
Text môže byť uložený do premennej vo forme reťazcu (string). Reťazec je vlastne pole písmen (`char`).

```cpp
char text[] = "Ahojte na kurze C++";

printf("obsah textu je: %s\n", text);
```


