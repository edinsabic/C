//
// Created by Edin on 23. 03. 2022.
//

#ifndef GITHUB_TERMINAL_H
#define GITHUB_TERMINAL_H

#include "World.h"
#include <curses.h>

void terminal_init();
int terminal_main();
void terminal_draw_world(World* world);

#endif //GITHUB_TERMINAL_H
