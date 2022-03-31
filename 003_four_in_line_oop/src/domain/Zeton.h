//
// Created by Edin on 23. 03. 2022.
//

#ifndef INSTRUKCIJE_D001_ZETON_H
#define INSTRUKCIJE_D001_ZETON_H

#include <stdbool.h>

typedef struct Zeton {
    int x;
    int y;
    char barva;
    bool porabljen;
} Zeton;

Zeton zeton_new(int x, int y, char barva);

#endif //INSTRUKCIJE_D001_ZETON_H
