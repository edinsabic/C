//
// Created by Edin on 15. 03. 2022.
//


#ifndef GITHUB_TERMINAL_H
#define GITHUB_TERMINAL_H

//Najprej so sistemski importi potem šele lokalni importi.
#include <curses.h>
#include <string.h>
#include <stdlib.h>

#include "World.h"
#include "utils.h"

typedef struct Terminal {
    int maxY;
    int maxX; 
    int steviloPolja; // za risanje pomoznega arraya
} Terminal;

typedef struct Terminal_input {
    int input; // de facto user's input (0 - 8)
    int x; // nadstropje memoTabele
    int y; // soba v nadstropju memoTabele
    // int isValid; // flag za veljavnost strukture
} Terminal_input;

void terminal_init();
Terminal terminal_new();
int terminal_main(Terminal* terminal);
Terminal_input terminal_input_new(int input, int x, int y);
Terminal_input terminal_get_input(World* world);
void terminal_validate_input(World* world, Terminal_input* input);
void terminal_draw_world(Terminal* terminal, World* world);

#endif //GITHUB_TERMINAL_H
