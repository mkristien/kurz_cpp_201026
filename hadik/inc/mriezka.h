
#pragma once

#include "datove_typy.h"

/**
 * Zobraz data z hada v mriezke
 */
void had_do_mriezky(meta_had* h, char** mriezka);

/**
 * Vytvor mriezku na zaciatku hry
 * ------------------
 * |XXXX@           |
 * |                |
 * |                |
 * ------------------
 */
meta_mriezka* init_mriezka(int riadky, int stlpce);

void print_mriezka(meta_mriezka* m);

void vytvor_potravu(meta_mriezka* m);

int mriezka_je_plna(meta_mriezka* m);
