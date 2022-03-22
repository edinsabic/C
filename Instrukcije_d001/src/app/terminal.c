//
// Created by Edin on 15. 03. 2022.
//

#include "terminal.h"
#include <curses.h>
#include <string.h>

void terminal_init() {
    initscr();
    curs_set(0);

    noecho();
    refresh();
}

_Noreturn int terminal_main() {
    World world = world_new();

    while (1) {
        terminal_draw_world(&world);

        char string[100];
        strcpy(string, "Enter a number between 1 and 9 to add your piece:");

        mvaddstr(0, 0, string);

        int c = getch() - '0';
        mvaddch(0, strlen(string) + 1, c + '0');

        move(3, 0);
        clrtoeol();

        if (c < 0 || c > 9) {
            mvaddstr(5, 0, "Just checking if everything works");
            mvaddstr(10, 3, "Your input is invalid, please try again!");
        }
    }
}

void terminal_draw_helperWorld(World* world) {
    int counter = 0;
    for (int y = 0; y < world->height; ++y) {
        for (int x = 0; x < world->width; ++x) {
            mvaddch(y + 2, x + 2,  counter + '0');
            counter++;
        }
    }
}

void terminal_draw_world(World* world) {
    terminal_draw_helperWorld(world);

    for (int y = 0; y < world->height; ++y) {
        for (int x = 0; x < world->width; ++x) {
            int flag = 0;

            for (int i = 0; i < WORLD_ST_ZETONOV; ++i) {
                Zeton* z = &world->zetoni[i];
                if (!z->aktiven) {
                    break;
                }
                if (z->y == y && z->x == x) {
                    mvaddch(y, x, z->barva);
                    flag = 1;
                    break;
                }
            }

            int maxY, maxX;
            getmaxyx(stdscr, maxY, maxX);

            if (!flag) {
                mvaddch(y + maxY / 2 - 1, x + maxX / 2 - 2, '.');
            }
        }
    }

    refresh();
}
