//
// Created by Edin on 23. 03. 2022.
//

#include "terminal.h"

void terminal_init(Terminal terminal) {
    initscr();
    curs_set(0);

    noecho();
    refresh();
}

Terminal terminal_new(int y, int x) {
    Terminal this;

    this = (Terminal){
        .maxY = x,
        .maxX = y,
    };

    return this;
}

Terminal_input terminal_input_new(int input) {
    Terminal_input this;

    this = (Terminal_input){
        .stStolpca = input
    };

    return this;
}

Terminal_input terminal_get_input(World* world) {
    mvaddstr(0, 0, "Enter a number between 0 and 8 to add your piece:");
    int vnos = getch() - '0'; // read the players input

    Terminal_input input = terminal_input_new(vnos);

    mvaddch(0, 50, vnos + '0');

    return input;
}

int terminal_main(Terminal* terminal) {
    World world = world_new();

    while (1) {
        terminal_draw_world(terminal, &world);

        if (world.active) {
            break;
        }

        if (world.frames > 10) {
            world.active = 1;
        }

        Terminal_input input = terminal_get_input(&world);

        world.frames++;
    }

    if (utils_get_platform_number() == 0) {
        system("cls");
    } else if (utils_get_platform_number() == 1) {
        system("clear");
    }

    return 0;
}

void terminal_draw_world(Terminal* terminal, World* world) {
    int maxY = terminal->maxY;
    int maxX = terminal->maxX;

    for (int y = 0; y < world->height; ++y) {
        for (int x = 0; x < world->width; ++x) {
            int flag = 0;

            for (int i = 0; i < WORLD_ST_ZETONOV; ++i) {
                Zeton* z = &world->zetoni[i];
                if (!z->aktiven) {
                    break;
                }
                if (z->y == y && z->x == x) {
                    mvaddch(y + maxY / 2 - 1, x + maxX / 2 - 2, z->barva);
                    flag = 1;
                    break;
                }
            }

            if (!flag) {
                mvaddch(y + maxY / 2 - 1, x + maxX / 2 - 2, '.');
            }
        }
    }

    refresh();
}
