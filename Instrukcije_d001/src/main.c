//
// Created by Edin on 15. 03. 2022.
//

#include <stdio.h>

#include "app/terminal.h"

int main() {
    Terminal terminal = terminal_new();
    terminal_init(&terminal);
    return terminal_main(&terminal);
}