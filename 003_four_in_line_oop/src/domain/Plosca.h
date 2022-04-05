//
// Created by Edin on 23. 03. 2022.
//

#ifndef INSTRUKCIJE_D001_PLOSCA_H
#define INSTRUKCIJE_D001_PLOSCA_H

#include "Zeton.h"

#define PLOSCA_ST_ZETONOV 42
#define PLOSCA_ST_VRSTIC 6
#define PLOSCA_ST_STOLPCEV 7

typedef struct Plosca {
    int height;
    int width;
    Zeton zetoni[PLOSCA_ST_ZETONOV];
    bool active;
    int stevec2DTabele; // Za štetje koliko potez je do sedaj
    int frames; // kdo bo na vrsti (omejen z PLOSCA_ST_ZETONOV)
    int memo_tabela[PLOSCA_ST_VRSTIC][PLOSCA_ST_STOLPCEV];
    int stolpci[PLOSCA_ST_STOLPCEV][PLOSCA_ST_VRSTIC];
    int counterjiStolpcev[PLOSCA_ST_STOLPCEV];
} Plosca;

Plosca plosca_new();

bool plosca_is_win(Plosca* plosca);
// These 4 private functions have "p_" prepended
bool p_plosca_check_vertical(Plosca* plosca, int num);
bool p_plosca_check_horizontal(Plosca* plosca, int num);
bool p_plosca_check_diagonal_1(Plosca* plosca, int num);
bool p_plosca_check_diagonal_2(Plosca* plosca, int num);

#endif //INSTRUKCIJE_D001_PLOSCA_H
