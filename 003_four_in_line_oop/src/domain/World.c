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
        .memo_tabela = {
                {0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0}
        }
    };

    for (int i = 0; i < WORLD_ST_ZETONOV; i++) {
        this.zetoni[i].aktiven = 0;
    }

    return this;
}