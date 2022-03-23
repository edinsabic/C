//
// Created by Edin on 15. 03. 2022.
//

#include "Zeton.h"

Zeton zeton_new(int x, int y, char XorO) {
    Zeton this;

    this.x = x;
    this.y = y;
    this.XorO = XorO;
    this.aktiven = 1;

    return this;
}