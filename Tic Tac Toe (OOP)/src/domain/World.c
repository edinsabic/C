//
// Created by Edin on 15. 03. 2022.
//

#include "World.h"

World world_new() { // ker imamo fixno dolzino ne rabimo parametrov
    World this;

    // Vedno pri prirejanju elementov struct dodaj type cast
    this = (World){
            .height = 3,
            .width = 3,
            .active = 0,
            .frames = 0,
            .memoTabela = {
                    {0,0,0},
                    {0,0,0},
                    {0,0,0}
            }
    };

    for (int i = 0; i < WORLD_ST_ZETONOV; i++) {
        this.zetoni[i].aktiven = 0;
    }

    return this;
}

// (return value) 0 - no winner detected, 1 - winner detected, 2 - it's a draw
int world_dinamicno_poisci_zmagovalca(World* world, int x, int y) {
    int enaALIdve = (world->frames % 2 == 0) ? 1 : 2;

    if (world->memoTabela[x][y] == 0) {
        world->memoTabela[x][y] = enaALIdve;
    }

    for (int i = 0; i < WORLD_SIRINA_BOARDA; i++) { //check col
        if (world->memoTabela[x][i] != enaALIdve) {
            break;
        } if (i == WORLD_SIRINA_BOARDA - 1) {
            return 1;
        }
    }

    for (int i = 0; i < WORLD_SIRINA_BOARDA; i++) { //check row
        if (world->memoTabela[i][y] != enaALIdve) {
            break;
        } if (i == WORLD_SIRINA_BOARDA - 1) {
            return 1;
        }
    }

    if (x == y) { // check the first diagonal
        //we're on a diagonal (narisi si)
        for (int i = 0; i < WORLD_SIRINA_BOARDA; i++) {
            if (world->memoTabela[i][i] != enaALIdve) {
                break;
            } if (i == WORLD_SIRINA_BOARDA - 1) {
                return 1;
            }
        }
    }

    if (x + y == WORLD_SIRINA_BOARDA - 1) { // check the other diagonal
        for (int i = 0; i < WORLD_SIRINA_BOARDA; i++) {
            if (world->memoTabela[i][(WORLD_SIRINA_BOARDA-1)-i] != enaALIdve) {
                break;
            } if (i == WORLD_SIRINA_BOARDA-1) {
                return 1;
            }
        }
    }

    if (world->frames == (WORLD_SIRINA_BOARDA * WORLD_SIRINA_BOARDA)) { // check draw
        return 2;
    }

    return 0;
}

void world_poteza(World* world, int input) {
    int zaVnest = (world->frames % 2) ? 1 : 2;
    int x = input / 3;
    int y = input % 3;
    world->memoTabela[x][y] = zaVnest;

    char znak = (world->frames % 2) ? 'O' : 'X';

    Zeton zeton = zeton_new(input % 3, input / 3, znak);
    world->zetoni[world->frames] = zeton; // dodelimo tabeli zetonov zeton

    world->frames++;
}