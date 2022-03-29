//
// Created by Edin on 15. 03. 2022.
//

#include "Zeton.h"

Zeton zeton_new(int x, int y, char znak) {
    Zeton this;

    this.x = x;
    this.y = y;
    this.znak = znak;
    this.aktiven = 1;

    return this;
}