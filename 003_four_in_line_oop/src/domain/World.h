//
// Created by Edin on 23. 03. 2022.
//

#ifndef INSTRUKCIJE_D001_WORLD_H
#define INSTRUKCIJE_D001_WORLD_H

#include "Zeton.h"

#define WORLD_ST_ZETONOV 42
#define WORLD_ST_VRSTIC 6
#define WORLD_ST_STOLPCEV 7

typedef struct World {
    int height;
    int width;
    Zeton zetoni[WORLD_ST_ZETONOV];
    int active; // ali je terminal ziv ali mrtev (igre konc al ne)
    int frames; // kdo bo na vrsti (omejen z WORLD_ST_ZETONOV)
    int stevec2DTabele;
    int memo_tabela[WORLD_ST_VRSTIC][WORLD_ST_STOLPCEV];
    int stolpci[WORLD_ST_STOLPCEV][WORLD_ST_VRSTIC];
    int counterjiStolpcev[WORLD_ST_STOLPCEV];
    int dvaDTabela[WORLD_ST_VRSTIC][WORLD_ST_STOLPCEV];
} World;

World world_new();

void world_popolnjenost_stolpcev(World* world, int* tabela, int stolpecCounter, int vrstica);
int world_is_win(World* world, int one, int two);
int world_check_vertical(int dvaDTabela[WORLD_ST_VRSTIC][WORLD_ST_STOLPCEV], int one);
int world_check_horizontal(int dvaDTabela[WORLD_ST_VRSTIC][WORLD_ST_STOLPCEV], int one);
int world_check_diagonal_2(int dvaDTabela[WORLD_ST_VRSTIC][WORLD_ST_STOLPCEV], int one);
int world_check_diagonal_1(int dvaDTabela[WORLD_ST_VRSTIC][WORLD_ST_STOLPCEV], int one);

#endif //INSTRUKCIJE_D001_WORLD_H
