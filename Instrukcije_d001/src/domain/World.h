//
// Created by Edin on 15. 03. 2022.
//

#ifndef INSTRUKCIJE_D001_WORLD_H
#define INSTRUKCIJE_D001_WORLD_H

#include "Zeton.h"

#define WORLD_ST_ZETONOV 9
#define ST_ZMAGOVALNIH_KOMBINACIJ 7

typedef struct World {
    int height;
    int width;
    Zeton zetoni[WORLD_ST_ZETONOV];
    int active; // flag za to, ali je terminal živ ali mrtev
    int frames; // counter za to kdo bo na vrsti (X ali 0) -> which frame we're at
    int memoTabela[WORLD_ST_ZETONOV];
    int zmagovalneKombinacije[ST_ZMAGOVALNIH_KOMBINACIJ][3];
} World;

World world_new();
int jeKdoZmagal(int tabela[ST_ZMAGOVALNIH_KOMBINACIJ][3], int memoTabela[WORLD_ST_ZETONOV], World world);
void poteza(World* world, int* memoTabela, int c);

#endif //INSTRUKCIJE_D001_WORLD_H
