//
// Created by Edin on 23. 03. 2022.
//

#include <stdio.h>
#include <stdbool.h>

#include "app/terminal.h"

int main() {
    Terminal terminal = terminal_new(50, 50);
    terminal_init(&terminal);
    return terminal_main(&terminal);
}