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
    int frames; // kdo bo na vrsti (omejen z PLOSCA_ST_ZETONOV)
    int stevec2DTabele;
    int memo_tabela[PLOSCA_ST_VRSTIC][PLOSCA_ST_STOLPCEV];
    int stolpci[PLOSCA_ST_STOLPCEV][PLOSCA_ST_VRSTIC];
    int counterjiStolpcev[PLOSCA_ST_STOLPCEV];
} Plosca;

Plosca plosca_new();

void plosca_popolnjenost_stolpcev(Plosca* plosca, int* tabela, int stolpecCounter);
bool plosca_is_win(Plosca* plosca, int one, int two);
bool plosca_check_vertical(int dvaDTabela[PLOSCA_ST_VRSTIC][PLOSCA_ST_STOLPCEV], int one);
bool plosca_check_horizontal(int dvaDTabela[PLOSCA_ST_VRSTIC][PLOSCA_ST_STOLPCEV], int one);
bool plosca_check_diagonal_2(int dvaDTabela[PLOSCA_ST_VRSTIC][PLOSCA_ST_STOLPCEV], int one);
bool plosca_check_diagonal_1(int dvaDTabela[PLOSCA_ST_VRSTIC][PLOSCA_ST_STOLPCEV], int one);

#endif //INSTRUKCIJE_D001_PLOSCA_H
