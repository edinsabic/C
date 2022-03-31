//
// Created by Edin on 23. 03. 2022.
//

#include "Zeton.h"

Zeton zeton_new(int x, int y, char barva) {
    Zeton this;

    this.x = x;
    this.y = y;
    this.barva = barva;
    this.porabljen = true;

    return this;
}