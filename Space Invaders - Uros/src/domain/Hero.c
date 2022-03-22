#include "Hero.h"
#include "Laser.h"

Hero hero_new(int x, int y) {
    Hero self;

    self.x = x;
    self.y = y;
    self.laser = laser_new(x, y);

    self.speed = 100;
    self.points = 0;
    self.lives = 3;

    return self;
}

void hero_move(Hero *self, int x, int y) {
    self->x += x;
    self->y += y;
}

void hero_shot(Hero *self) {
    self->laser.x = self->x;
    self->laser.y = self->y;
    self->laser.is_alive = 1;
}

