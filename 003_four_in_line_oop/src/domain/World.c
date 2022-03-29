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

void world_popolnjenostStolpcev(World* world, int* tabela, int stolpecCounter, int vrstica) {
    tabela[stolpecCounter] = (world->frames % 2 == 0) ? 1 : 2;

    world->memo_tabela[stolpecCounter][vrstica - 1] = (world->frames % 2 == 0) ? 1 : 2;
    world->stevec2DTabele++;
}
/*
 */