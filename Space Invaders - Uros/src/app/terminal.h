//
// Created by urosjarc on 16. 12. 19.
//

#include "World.h"

#ifndef CGAME_TERMINAL_H
#define CGAME_TERMINAL_H

#endif //CGAME_TERMINAL_H

void terminal_init();

int terminal_main();

void terminal_msg(World *world, char msg[], int slp);

void terminal_draw_infos(World *world, int round);

void terminal_draw_world(World *world);
