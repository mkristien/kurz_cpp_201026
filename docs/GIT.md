# GIT - ako zdieľať kód

Program `git` slúži na prácu s projektami/úložiskami kódu v cloude.

V tomto kurze budeme používať vzdialené cloudové úložisko na servery GitHub.
Dokumentáciu ku kurzu a vzorové zdrojové kódy si môžeš pozrieť priamo na tomto linku:
https://github.com/mkristien/kurz_cpp_201026

Ak si chceš stiahnuť úložisko do svojho počítača, stačí v terminály zadať:
```
git clone https://github.com/mkristien/kurz_cpp_201026.git
```
Tento príkaz vytvorí novú zložku `kurz_cpp_201026`, v ktorej nájdeš súbory lokálneho úložiska.

Pre stiahnutie nových súborov zo vzdialeného úložiska, môžes synchronizovať svoje lokálne úložisko takto:
```
cd kurz_cpp_201026
git pull
```

Ak by v tomto bode nastali nejaké problémy, vždy môžeš celé úložisko vymazať a naklonovať ho znova s pomocou `git clone` ako na začiatku.

