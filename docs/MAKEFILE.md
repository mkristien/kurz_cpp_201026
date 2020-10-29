# Makefile - ako skompilovať project

Makefile je súbor v ktorom môžeme špecifikovať akým spôsobom alebo akými príkazmy chceme skompilovať našu aplikáciu. Výhoda takéhoto prístupu je v tom, že nemusíme manuálne zadávať príkazy do terminálu, dokonca si ani nemusíme pamätať aké príkazy treba.

## Štruktúra
V Makefile môžeme mať viacero cieľov kompilácie (i.e. viacero aplikácii ktoré chceme skompilovať). Každý cieľ má približne nasledovnú štruktúru.
```
<ciel> : <list zavyslosti>
	<list prikazov>

e.g.:
input.exe : input.cpp
	echo "kompilujem"
	gcc -o input.exe input.cpp
	echo "skompilovane"
```
List závyslostí môže obsahovať viacero iných cieľov alebo viacero súborov zdrojového kódu od ktorých náš cieľ závysí. List závyslostí je dôležitý na to aby program `make` vedeľ vyhodnotiť ktoré ciele treba rekompilovať. List príkazov pre daný cieľ sa spustí iba ak nastala zmena v aspoň jednej závislostí daného cieľu odkedy sa naposledy cieľ kompiloval.

## Používanie
Väčšina `Makefile` súborov je napísana tak, aby pre najbežnejšie ciele stačilo v terminály zadať `make`. Pri takomto príkaze sa vykoná vždy prvý cieľ v súbore `Makefile`.
```
make            # skompiluj prvy ciel
make <ciel>     # skompiluj dany ciel
```

## Ďalšie funkcie
Ak nechceme, aby príkazy pri kompilovaní cieľov neboli vypísané do výstupu, stačí na začiatok príkazu pridať `@`.
### Premenné
Do `Makefile` premenných si môžeme zapísať ľubovoľné hodnoty. Napríklad, v premennej `SRCS` môžeme mať uložené názvy všetkých zdrojových súborov. Premmenné môžeme použiť takto: `$(SRCS)`
```Makefile
SRCS = argumenty.cpp nasobky.cpp pole_int.cpp pole_double.cpp

info:
	@echo "premenna SRCS ma hodnotu $(SRCS)"
```

### Nahradenie menších reťazcov v slovách
S použitím funkcie `patsubst` môžeme časti slov nahradiť inými slovami. Táto funkcia je užitočná na nahradenie včetkých názvov súborov zdrojového kódu názvami exe súborov.

Syntax:\
`$(patsubst <vzorez vo vstupe>, <vzorec vo vystupe>, <vstupny text>)`

```Makefile
# Premen vsetky .cpp nazvy na rovnake .exe nazvy
# Do Premennej EXES na zapise "jeden.exe dva.exe"
EXES = $(patsubst %.cpp, %.exe, jeden.cpp dva.cpp)
```
[Viac info](https://www.gnu.org/software/make/manual/html_node/Text-Functions.html).
### Automatické premmenné
Aby sme nemuseli pre každý cieľ zbytočne vypisovať názovy súborov, použijeme automatické premenné. Premenná `$@` bude nahradená hodnotou cieľa, premenná `$<` bude nahradená hodnotou závislosti.

```Makefile
hello.exe : hello.cpp
	gcc -o $@ $<	# gcc -o hello.exe hello.cpp
```
[Viac info](https://riptutorial.com/makefile/example/21469/automatic-variables).

### Vzorcové ciele
Aby sme nemuseli podobné ciele viackrát vypisovať, môžeme napísať jedno pravidlo, napr. ako skompilovať všetky `.exe` súbory.

Rovnako ako pri použití `patsubst`, znak `%` zastáva zhodojúcu sa časť medzi cieľom a závislosťou (i.e. koreň).

```Makefile
# Pravidlo kompilacie pre vsetky .exe ciele
%.exe : %.cpp
	@echo "kompilujem $< do $@"
	gcc -o $@ $<
```
[Viac info](https://www.gnu.org/software/make/manual/html_node/Pattern-Rules.html#Pattern-Rules).
