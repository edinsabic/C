//
// Created by Edin on 15. 03. 2022.
//

#ifndef GITHUB_TERMINAL_H
#define GITHUB_TERMINAL_H

#include "World.h"

void terminal_init();

_Noreturn int terminal_main();
void terminal_draw_world(World* world);
void terminal_draw_helperWorld(World* world);

#endif //GITHUB_TERMINAL_H
