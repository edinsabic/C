//
// Created by urosjarc on 16. 12. 19.
//

#include "Hero.h"
#include "Enemy.h"
#include "Laser.h"

#ifndef CGAME_WORLD_H
#define CGAME_WORLD_H

typedef struct World {
    int width;
    int height;
    Hero hero;
    Enemy enemies[9];
} World;

/**
 * Create new world.
 * @return: World structure.
 */
World world_new();

/**
 * Create brand new enemies!
 * @param self
 */
void world_new_enemies(World *self);

/**
 * Process world movement and key press events.
 * @param key Keyboard pressed character.
 */
void world_event(World *, char key);

/**
 * Move enemies by one iteration.
 */
void world_move_enemy(World *);

/**
 * Move hero laser if laser is active and alive.
 * @return: Enemies that are currently alive.
 */
int world_move_hero_laser(World *);

/**
 * Move enemy lasers.
 * @return 1 or 0 if hero was hit on laser move.
 */
int world_move_enemy_lasers(World *);

/**
 * Count enemy starting number.
 * @return Max enemies.
 */
int world_enemy_num(World *);

#endif //CGAME_WORLD_H
