# BASH - terminál
[Bash - Wiki](https://en.wikipedia.org/wiki/Bash_(Unix_shell))

`Bash` je jeden z najobľúbenejších terminálov pre systémy UNIX (Linux, Mac). Na Windowse tiež môžeme používať tento terminál pomocou programu `cygwin`.

## Základné príkazy

### Komentár
Príkazy začínajúce s `#` sú iba komentár a nemajú vplyv na správanie terminálu.
```
$ # toto nic nespravi

```

### `echo <text>`
Output/povedz niečo.
```
$ echo "Ahoj AjTyvIT"
Ahoj AjTyvIT
```

### `pwd` - print working directory
Zobrazí aktuálnu pozíciu terminálu v rámci zložiek na disku počítača.
```
$ pwd
/home/martin
```

### `cd <path>` - change directory
Zmení aktuálnu pozíciu terminálu.

Argument `path` je nepovinný. Tento argument môže byť relatívny k aktuálnej pozícií alebo absolútny.

```
$ pwd
/home/martin/ajtyvit/kurz_cpp_201026
$ cd docs                                   # relativny path
$ pwd
/home/martin/ajtyvit/kurz_cpp_201026/docs
$ cd ../../                                 # relativny path, chod dva levely hore
$ pwd
/home/martin/
$ cd /home/martin/ajtyvit/kurz_cpp_201026   # absolutny path
$ pwd
/home/martin/ajtyvit/kurz_cpp_201026
$ cd                                        # chod domov, rovnake ako "cd ~"
```

### `clear`
Vyčisti obrazovku.

### `ls` - list
Zobraz priečinky a súbory na aktuálnej pozícii.
```
$ ls
docs  README.md  src
$ ls -l                                         # -l pre viac informacii
total 1
drwxr-xr-x+ 1 marti marti   0 Oct 26 16:17 docs
-rwxr-xr-x  1 marti marti 430 Oct 26 16:21 README.md
drwxr-xr-x+ 1 marti marti   0 Oct 26 18:46 src
```

### `touch <subor>`
Dostkni sa súboru. Ak súbor neexistuje, `touch` vytvorí nový súbor. Ak súbor existuje, `touch` zmení čas poslednej zmeny súboru na aktuálny čas.

### `mkdir <zlozka>`
Vytvor novú zložku.

### `rm <subor>` / `rmdir <zlozka>`
Vymaž súbor/zložku. Pozor, vymazanie neznamená zahodiť do koša. Vymazané súbory sa nedajú obnoviť.

### `which <program>`
Skontroluje, či je zadaný program nainštalovaný. Ak áno, ukáže cestu k programu.
```
$ which gcc
/usr/bin/gcc
$ which cdsacsd
which: no cdsacsd in (/usr/local/bin:/usr/bin:/cygdrive/c/Windows/system32: ...
```

### `cat <subor>` / `less <subor>`
Prečítaj obsah súboru. Program `cat` vypluje obsah súboru priamo do terminálu. Program `less` otvorí súbor v špecialnom náhľade v terminály pre pohodlnejšie čítanie. V náhľade sa môžeme šípkami pohybovať v rámci súboru hore dole. Náhľad sa zatvorí stlačením klávesy `q` (quit).

### `man <program>`
Otvorí manuál/dokumentáciu daného programu. Dokumentácia je otvorená v náhľade podobne ako pri programe `less`.

Väčšina progamov má viac fukncii ako je opísaných v tomto dokumente. Manuál poskytuje opis týchto funkcii skoro pre všetky programy.

### `time <prikaz + argumenty>`
Odmeraj, ako dlho trvá vykonanie daného príkazu. Takto môžeme merať rýchlosť nážho programu.
```bash
$ time sleep 5
real    0m5.052s    # celkovy cas od spustenia programu po ukoncenie
user    0m0.000s    # cas straveny vykonom kodu samotneho programu
sys     0m0.016s    # cas straveny vykonavanim sluzieb operacneho systemu
```

### `find <zlozka>`
Vyhľadaj všetky súbory a zložky v danej zložke. Tento príkaz je podobný príkazu `ls`, ale vo výsledku sa nachádzajú aj súbory v pod-zložkách.

```bash
$ find src/lekcia_1
src/lekcia_1
src/lekcia_1/hello.cpp
src/lekcia_1/input.cpp
src/lekcia_1/Makefile
```

### `grep <text> <subor>`
Prečítaj súbor a vypíš iba riadký, v ktorých sa nachádza daný kúsok textu.
```bash
$ cat temp.txt
Ahoj v ajtyvit
Za kratky cas sme sa toho vela naucili.
Program ajtyvit je super.
Takymto tempom zo mna za chvilu bude IT expertka.

$ grep ajtyvit temp.txt
Ahoj v ajtyvit
Program ajtyvit je super.
```

### `wc <subor>`
Word count - počítač slov. Príkaz zobrazí počeť riadkov, slov, a písmen v zadanom súbore.
```bash
$ wc temp.txt
  4  24 131 temp.txt
```

## Ako spájať programy
Viaceré programy môžeme spustiť naraz a prepojiť ich s použitím symbolu `|`. Tento symbol použije výstup z prvého programu ako vstup do druhého programu.

```bash
$ grep ajtyvit temp.txt
Ahoj v ajtyvit
Program ajtyvit je super.

$ # to iste ako:
$ cat temp.txt | grep ajtyvit
Ahoj v ajtyvit
Program ajtyvit je super.
```

Takýmto spôsobom môžeme spojiť aj viacero programov:
1. Nájdi všetky súbory v zložke `src`.
```bash
$ find src
```
2. Nájdi všetky súbory v zložke `src` a vyfiltru iba súbory zdrojového kódu `cpp`.
```bash
$ find src | grep cpp
```
3. Vypíš obsah všetkých zdrojových súborov. Použi funkciu `xargs` aby jednotlivé názvy súborov neboli input do ďalšieho programu ale argumenty ďalšieho programu.
```bash
$ find src | grep cpp | xargs cat
```
4. Spočítaj riadky kódu vo všetkých zdrojových súborov v zložke `src`.
```bash
$ find src | grep cpp | xargs cat | wc -l
563
```
