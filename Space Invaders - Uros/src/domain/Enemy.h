//
// Created by urosjarc on 15. 12. 19.
//

#ifndef CGAME_ENEMY_H
#define CGAME_ENEMY_H

#include "Laser.h"

int ENEMY_speed;
int ENEMY_x_move_direction;

typedef struct Enemy {
    int is_alive;
    int x;
    int y;
    Laser laser;
} Enemy;

Enemy enemy_new(int x, int y);

void enemy_shot(Enemy *);

void enemy_move(Enemy *);

void enemy_move_down(Enemy *);

#endif //CGAME_ENEMY_H
