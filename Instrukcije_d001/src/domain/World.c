//
// Created by Edin on 15. 03. 2022.
//

#include "World.h"

World world_new() { // ker imamo fixno dolzino ne rabimo parametrov
    World this;

    // Vedno pri prirejanju elementov struct dodaj type cast
    this = (World){.height = 3, .width = 3, .active = 0, .frames = 0, .zmagovalneKombinacije = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{0,4,8},{2,4,6}}};

    for (int i = 0; i < WORLD_ST_ZETONOV; i++) {
        this.zetoni[i].aktiven = 0;
    }

    return this;
}

/*
void dinamicnoPoisciZmagovalca() {

}
 */

/*
// Zakaj memoTabela mora bit const?
int jeKdoZmagal(int tabela[ST_ZMAGOVALNIH_KOMBINACIJ][3], int memoTabela[WORLD_ST_ZETONOV], World world) {
    for (int i = 0; i < ST_ZMAGOVALNIH_KOMBINACIJ; ++i) {
        if ((memoTabela[tabela[i][0]] > 0 && memoTabela[tabela[i][1]] > 0 && memoTabela[tabela[i][2]] > 0)
            && (memoTabela[tabela[i][0]] == memoTabela[tabela[i][1]])
            && (memoTabela[tabela[i][0]] == memoTabela[tabela[i][2]])) {

            // world.active = 1;
            return 1;
        }
    }

    return 0;
}

*/

void poteza(World* world, int memoTabela[SIRINA_BOARDA][SIRINA_BOARDA], int input) {
    int zaVnest = (world->frames % 2) ? 1 : 2;
    int x = input / 3;
    int y = input % 3;
    memoTabela[x][y] = zaVnest;

    char znak = (world->frames % 2) ? 'O' : 'X';

    Zeton zeton = zeton_new(input % 3, input / 3, znak);
    world->zetoni[world->frames] = zeton; // dodelimo tabeli zetonov zeton

    world->frames++;
}