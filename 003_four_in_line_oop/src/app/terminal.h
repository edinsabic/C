//
// Created by Edin on 23. 03. 2022.
//

#ifndef GITHUB_TERMINAL_H
#define GITHUB_TERMINAL_H

#include <curses.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Plosca.h"
#include "utils.h"

typedef struct Terminal {
    int maxY;
    int maxX;
} Terminal;

typedef struct Terminal_input {
    int stStolpca; // Za povedat kam dropat žeton
} Terminal_input;

void terminal_init(Terminal* terminal);
Terminal terminal_new(int y, int x);
Terminal_input terminal_get_input(Plosca* plosca);
Terminal_input terminal_input_new(int input);
void terminal_validate_input(Terminal_input input, Plosca* plosca);
void terminal_draw_plosca(Terminal* terminal, Plosca* plosca);
int terminal_main(Terminal* terminal);
void terminal_spuscanje_zetona(Terminal_input* input, Plosca* plosca);

#endif //GITHUB_TERMINAL_H
