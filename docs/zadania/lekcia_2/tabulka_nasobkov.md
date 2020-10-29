# Tabulka násobkov

Kto si ešte pamätá násobilku zo školy?

Skúsme si napísať program, ktorý do výstupu napíše tabuľku násobilky.

Program bude musieť zmeniť správanie podla inputu zadaného užívateľkou. Konkrétne by mala byť užívateľka schopná povedať programu koľko riadkov a stĺpcov má násobilka obsahovať.

## Špecifikácia input/output
```
$ ./tabulka_nasobkov.exe
Prosim, zadaj pocet riadkov a stlpcov nasobilky
./tabulka_nasobkov.exe <pocet riadkov> <pocet stlpcov>

$ ./tabulka_nasobkov.exe 1 1
1 * 1 = 1

$ ./tabulka_nasobkov.exe 3 2
1 * 1 = 1   1 * 2 = 2
2 * 1 = 2   2 * 2 = 4
3 * 1 = 3   3 * 2 = 6

$ ./tabulka_nasobkov.exe 2 3
1 * 1 = 1   1 * 2 = 2   1 * 3 = 3
2 * 1 = 2   2 * 2 = 4   2 * 3 = 6
```

Alternatívne formátovanie:
```
$ ./tabulka_nasobkov.exe 6 5
        1   2   3   4   5
---------------------------
1   |   1   2   3   4   5
2   |   2   4   6   8   10
3   |   3   6   9   12  15
4   |   4   8   12  16  20
5   |   5   10  15  20  25
6   |   6   12  18  24  30
```