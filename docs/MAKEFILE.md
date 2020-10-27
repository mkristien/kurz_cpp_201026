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


