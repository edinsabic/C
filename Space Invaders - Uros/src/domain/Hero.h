//
// Created by urosjarc on 15. 12. 19.
//

#ifndef CGAME_HERO_H
#define CGAME_HERO_H

#include "Laser.h"

typedef struct Hero {
    Laser laser;
    int lives;
    int speed;
    int points;
    int x;
    int y;
} Hero;

Hero hero_new(int x, int y);

void hero_move(Hero *, int x, int y);

void hero_shot(Hero *);

#endif //CGAME_HERO_H
