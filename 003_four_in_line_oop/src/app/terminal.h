//
// Created by Edin on 23. 03. 2022.
//

#ifndef GITHUB_TERMINAL_H
#define GITHUB_TERMINAL_H

#include <curses.h>
#include <stdlib.h>

#include "World.h"
#include "utils.h"

typedef struct Terminal {
    int maxY;
    int maxX;
    int stevilkaStolpca;
} Terminal;

typedef struct Terminal_input {
    int stStolpca; // Za povedat kam dropat žeton
} Terminal_input;

void terminal_init(Terminal* terminal);
Terminal terminal_new(int y, int x);
Terminal_input terminal_get_input(World* world);
Terminal_input terminal_input_new(int input);
void terminal_validate_input(Terminal_input input, World* world);
void terminal_draw_world(Terminal* terminal, World* world);
int terminal_main(Terminal* terminal);

#endif //GITHUB_TERMINAL_H
