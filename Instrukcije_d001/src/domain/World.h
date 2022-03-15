//
// Created by Edin on 15. 03. 2022.
//

#ifndef INSTRUKCIJE_D001_WORLD_H
#define INSTRUKCIJE_D001_WORLD_H

#include "Zeton.h"

#define WORLD_ST_ZETONOV 9

typedef struct World {
    int height;
    int width;
    Zeton zetoni[WORLD_ST_ZETONOV];
} World;

World world_new();

#endif //INSTRUKCIJE_D001_WORLD_H
