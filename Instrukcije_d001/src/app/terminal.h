//
// Created by Edin on 15. 03. 2022.
//


/* V H datotekah ne bomo imeli spremenljivk,
 * te bodo normalno v C datotekah
 * */
#ifndef GITHUB_TERMINAL_H
#define GITHUB_TERMINAL_H

#include "World.h"
#include <curses.h>
#include <string.h>
#include <stdlib.h>

void terminal_init();
int terminal_main();
void terminal_draw_world(World* world);

#endif //GITHUB_TERMINAL_H
