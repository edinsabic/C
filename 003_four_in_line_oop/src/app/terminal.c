//
// Created by Edin on 23. 03. 2022.
//

#include "terminal.h"

void terminal_init() {
    initscr();
    curs_set(0);

    noecho();
    refresh();
}

int terminal_main() {
    World world = world_new();


    while (1) {

        terminal_draw_world(&world);
    }


    return 0;
}

void terminal_draw_world(World* world) {
    for (int y = 0; y < world->height; ++y) {
        for (int x = 0; x < world->width; ++x) {
            int flag = 0;

            for (int i = 0; i < WORLD_ST_ZETONOV; ++i) {
                Zeton* z = &world->zetoni[i];
                if (!z->aktiven) {
                    break;
                }
                if (z->y == y && z->x == x) {
                    mvaddch(y + 2, x + 2, z->barva);
                    flag = 1;
                    break;
                }
            }

            if (!flag) {
                mvaddch(y + 2, x + 2, '.');
            }
        }
    }

    refresh();
}
