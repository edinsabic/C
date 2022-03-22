//
// Created by urosjarc on 16. 12. 19.
//

#include "Laser.h"

int LASER_speed = 10;

Laser laser_new(int x, int y) {
    Laser self;

    self.is_alive = 0;
    self.x = x;
    self.y = y;

    return self;
}

void laser_move(Laser *self, int x, int y) {
    self->x += x;
    self->y += y;
}
