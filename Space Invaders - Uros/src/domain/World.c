//
// Created by urosjarc on 16. 12. 19.
//

#include <stdlib.h>
#include "World.h"
#include "Enemy.h"


World world_new() {
    World self;

    self.height = 10;
    self.width = 20;
    self.hero = hero_new(self.width / 2, self.height);

    world_new_enemies(&self);

    return self;
}

void world_new_enemies(World *self){
    int enemy_num = world_enemy_num(self);
    ENEMY_x_move_direction = 1;
    for (int i = 0; i < enemy_num; i++)
        self->enemies[i] = enemy_new(i + 1, 0);
}

void world_event(World *self, char key) {

    //MOVING HERO
    Hero *hero = &self->hero;
    int dx = 0;
    if (key == 'h' && hero->x > 1) dx = -1;
    else if (key == 'l' && hero->x < self->width - 1) dx = 1;
    else if (key == 'x' && !hero->laser.is_alive) hero_shot(hero);
    hero_move(hero, dx, 0);

    //MOVING ENEMY ENEMIES & THEIR LASERS
    int enemy_num = world_enemy_num(self);
    for (int i = 0; i < enemy_num; i++) {
        Enemy *enemy = &self->enemies[i];
        int shoot = !(int)((float)rand()/RAND_MAX * 1000);
        if (enemy->is_alive && shoot && !enemy->laser.is_alive) {
            enemy_shot(enemy);
        }
    }


}

void world_move_enemy(World *self) {

    int enemy_num = world_enemy_num(self);
    int enemy_wall_collision = 0;

    if ((ENEMY_x_move_direction == 1 && self->enemies[enemy_num - 1].x == self->width) ||
        (ENEMY_x_move_direction == -1 && self->enemies[0].x == 1)) {

        enemy_wall_collision = 1;
        ENEMY_x_move_direction *= -1;
    }

    for (int i = 0; i < enemy_num; i++) {
        Enemy *enemy = &self->enemies[i];

        if (enemy_wall_collision) {
            enemy_move_down(enemy);
        } else enemy_move(enemy);
    }

}

int world_move_hero_laser(World *self) {
    Laser *laser = &self->hero.laser;
    //MOVING HERO LASER
    if (laser->is_alive> 0) {
        laser_move(laser, 0, -1);
        if (laser->y == -1) {
            laser->is_alive = 0;
        }
    }

    //CHECK LASER COLLISION WITH ENEMY
    int enemy_num = world_enemy_num(self);
    int enemy_alive_num = 0;
    for (int i = 0; i < enemy_num; i++) {
        Enemy *enemy = &self->enemies[i];
        if (laser->is_alive && enemy->is_alive && enemy->x == laser->x && enemy->y == laser->y) {
            enemy->is_alive = 0;
            laser->is_alive = 0;
            self->hero.points++;
        }
        if (enemy->is_alive) enemy_alive_num++;
    }

    return enemy_alive_num;
}

int world_move_enemy_lasers(World *self) {
    int laser_num = world_enemy_num(self);
    int hero_hit = 0;

    for (int i = 0; i < laser_num; i++) {
        Laser *laser = &self->enemies[i].laser;

        if (laser->is_alive) {
            laser_move(laser, 0, 1);

            if(self->hero.y == laser->y && self->hero.x == laser->x){
                hero_hit = 1;
                self->hero.lives--;
            }

            if (laser->y == self->height)
                laser->is_alive = 0;
        }
    }

    return hero_hit;
}

int world_enemy_num(World *self) {
    return sizeof(self->enemies) / sizeof(Enemy);
}
