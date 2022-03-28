//
// Created by Edin on 15. 03. 2022.
//


#ifndef GITHUB_TERMINAL_H
#define GITHUB_TERMINAL_H

#include "World.h"
#include <curses.h>
#include <string.h>
#include <stdlib.h>

#if defined(_WIN32)
#define PLATFORM_NUMBER 0 // Windows
#elif defined(_WIN64)
#define PLATFORM_NUMBER 0 // Windows
#elif defined(__linux__)
#define PLATFORM_NUMBER 1 // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other
#endif

typedef struct Terminal {
    int maxY;
    int maxX;
    int input;
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
int terminal_main();
Terminal_input terminal_input_new(int input, int x, int y);
Terminal_input terminal_get_input();
void terminal_draw_world(World* world);
int get_platform_number();

#endif //GITHUB_TERMINAL_H
