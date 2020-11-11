
#pragma once

// nove datove typy
enum smer { dolava, doprava, dole, hore, ziaden};

struct bod {
  int x;  // stlpec
  int y;  // riadok
};

struct meta_had {
  bod*  had;
  int   had_dlzka;
  smer  had_smer;
  bod   vymazany_chvost;
};

struct meta_mriezka {
  int     riadky;
  int     stlpce;
  char**  mriezka;
};
