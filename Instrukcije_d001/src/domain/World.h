//
// Created by Edin on 15. 03. 2022.
//

#ifndef INSTRUKCIJE_D001_WORLD_H
#define INSTRUKCIJE_D001_WORLD_H

#include "Zeton.h"

#define WORLD_ST_ZETONOV 9
#define ST_ZMAGOVALNIH_KOMBINACIJ 7
#define SIRINA_BOARDA 3

typedef struct World {
    int height;
    int width;
    Zeton zetoni[WORLD_ST_ZETONOV];
    int active; // flag za to, ali je terminal živ ali mrtev
    int frames; // counter za to kdo bo na vrsti (X ali 0) -> which frame we're at
    int memoTabela[SIRINA_BOARDA][SIRINA_BOARDA];
} World;

World world_new();
int dinamicnoPoisciZmagovalca(int x, int y, int enaALIdve, int memoTabela[SIRINA_BOARDA][SIRINA_BOARDA], World* world);
void poteza(World* world, int memoTabela[SIRINA_BOARDA][SIRINA_BOARDA], int c);

#endif //INSTRUKCIJE_D001_WORLD_H
