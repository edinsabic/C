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
    int counter;
    int input;
} Terminal;

void terminal_init();
int terminal_main();
void terminal_draw_world(World* world);
void terminal_izpisi_in_pucanje(int c);
int get_platform_number();

#endif //GITHUB_TERMINAL_H
