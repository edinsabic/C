//
// Created by Edin on 23. 03. 2022.
//

#include "World.h"

World world_new() { // ker imamo fixno dolzino ne rabimo parametrov
    World this;

    this = (World){
        .height = WORLD_ST_VRSTIC,
        .width = WORLD_ST_STOLPCEV,
        .active = 0,
        .frames = 0,
        .stevec2DTabele = 0,
    };

    for (int i = 0; i < WORLD_ST_ZETONOV; i++) {
        this.zetoni[i].aktiven = 0;
    }

    for (int i = 0; i < WORLD_ST_VRSTIC; i++) {
        for (int j = 0; j < WORLD_ST_STOLPCEV; j++) {
            this.memo_tabela[i][j] = 0;
        }
    }

    for (int i = 0; i < WORLD_ST_STOLPCEV; i++) {
        for (int j = 0; j < WORLD_ST_VRSTIC; j++) {
            this.stolpci[i][j] = 0;
        }
    }

    for (int i = 0; i < WORLD_ST_STOLPCEV; i++) {
        this.counterjiStolpcev[i] = 0;
    }

    return this;
}

void world_popolnjenost_stolpcev(World* world, int* tabela, int stolpecCounter, int vrstica) {
    tabela[stolpecCounter] = (world->frames % 2 == 0) ? 1 : 2;

    world->stevec2DTabele++;
}

int world_check_vertical(int dvaDTabela[WORLD_ST_VRSTIC][WORLD_ST_STOLPCEV], int one) {
    for (int i = 0; i < WORLD_ST_STOLPCEV; i++){
        if ((dvaDTabela[0][i] == one && dvaDTabela[1][i] == one && dvaDTabela[2][i] == one && dvaDTabela[3][i] == one))
            return 1;
        if ((dvaDTabela[1][i] == one && dvaDTabela[2][i] == one && dvaDTabela[3][i] == one && dvaDTabela[4][i] == one))
            return 1;
        if ((dvaDTabela[2][i] == one && dvaDTabela[3][i] == one && dvaDTabela[4][i] == one && dvaDTabela[5][i] == one))
            return 1;
    }

    return 0;
}

int world_check_horizontal(int dvaDTabela[WORLD_ST_VRSTIC][WORLD_ST_STOLPCEV], int one) {
    for (int i = 0; i < WORLD_ST_VRSTIC; i++) {
        if ((dvaDTabela[i][0] == one && dvaDTabela[i][1] == one && dvaDTabela[i][2] == one && dvaDTabela[i][3] == one))
            return 1;
        if ((dvaDTabela[i][1] == one && dvaDTabela[i][2] == one && dvaDTabela[i][3] == one && dvaDTabela[i][4] == one))
            return 1;
        if ((dvaDTabela[i][2] == one && dvaDTabela[i][3] == one && dvaDTabela[i][4] == one && dvaDTabela[i][5] == one))
            return 1;
        if ((dvaDTabela[i][3] == one && dvaDTabela[i][4] == one && dvaDTabela[i][5] == one && dvaDTabela[i][6] == one))
            return 1;
    }
    return 0;
}

int world_check_diagonal_1(int dvaDTabela[WORLD_ST_VRSTIC][WORLD_ST_STOLPCEV], int one) {
    for (int i = 0; i < WORLD_ST_VRSTIC; i++) {
        for (int j = 0; j < WORLD_ST_STOLPCEV; j++) {
            if (i < WORLD_ST_VRSTIC - 3 && j < WORLD_ST_STOLPCEV - 3) {
                if ((dvaDTabela[i][j] == one && dvaDTabela[i+1][j+1] == one && dvaDTabela[i+2][j+2] == one && dvaDTabela[i+3][j+3] == one))
                    return 1;
            }
        }
    }
    return 0;
}

int world_check_diagonal_2(int dvaDTabela[WORLD_ST_VRSTIC][WORLD_ST_STOLPCEV], int one) {
    for (int i = 0; i < WORLD_ST_VRSTIC; i++) {
        for (int j = 0; j < WORLD_ST_STOLPCEV; j++) {
            if (i < WORLD_ST_VRSTIC - 3 && j > WORLD_ST_STOLPCEV - 5) {
                if ((dvaDTabela[i][j] == one && dvaDTabela[i+1][j-1] == one && dvaDTabela[i+2][j-2] == one && dvaDTabela[i+3][j-3] == one))
                    return 1;
            }
        }
    }
    return 0;
}

int world_is_win(World* world, int one, int two) {
    if (world_check_vertical(world->memo_tabela, one) || world_check_vertical(world->memo_tabela, two))
        return 1;
    if (world_check_horizontal(world->memo_tabela, one) || world_check_horizontal(world->memo_tabela, two))
        return 1;
    if (world_check_diagonal_1(world->memo_tabela, one) || world_check_diagonal_1(world->memo_tabela, two))
        return 1;
    if (world_check_diagonal_2(world->memo_tabela, one) || world_check_diagonal_2(world->memo_tabela, two))
        return 1;
    return 0;
}