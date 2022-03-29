//
// Created by Edin on 15. 03. 2022.
//

#ifndef INSTRUKCIJE_D001_WORLD_H
#define INSTRUKCIJE_D001_WORLD_H

#include "Zeton.h"

#define WORLD_ST_ZETONOV 9
#define WORLD_SIRINA_BOARDA 3

typedef struct World {
    int height;
    int width;
    Zeton zetoni[WORLD_ST_ZETONOV];
    int active; // flag za to, ali je terminal živ ali mrtev
    int frames; // counter za to kdo bo na vrsti (X ali 0) -> which frame we're at
    int memoTabela[WORLD_SIRINA_BOARDA][WORLD_SIRINA_BOARDA];
} World;

World world_new();
int world_dinamicno_poisci_zmagovalca(World* world, int x, int y);
void world_poteza(World* world, int c);

#endif //INSTRUKCIJE_D001_WORLD_H
