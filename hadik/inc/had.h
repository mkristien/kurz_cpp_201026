
#pragma once

#include "datove_typy.h"

/**
 * Vytvor hada na zaciatku hry
 */
meta_had* init_had(int max_dlzka);

/**
 * Zmen data o hadovi podla toho, ktorym smerom sa hybe
 */
void had_pohyb(meta_had* h, smer novy_smer);

void had_sa_najedol(meta_had* h);
