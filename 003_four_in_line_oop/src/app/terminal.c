//
// Created by Edin on 23. 03. 2022.
//

#include "terminal.h"

void terminal_init(Terminal* terminal) {
    initscr();
    curs_set(0);

    noecho();
    refresh();
}

Terminal terminal_new(int y, int x) {
    Terminal this;

    this = (Terminal){
        .maxY = x,
        .maxX = y
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
    mvaddstr(0, 0, "Enter a number between 0 and 6 to add your piece:");
    int vnos = getch() - '0'; // read the players input

    Terminal_input input = terminal_input_new(vnos);

    mvaddch(0, 50, vnos + '0');

    // to je za popucat napačne inpute (šele naslednjo iteracijo)
    move(10, 0); clrtoeol();
    move(4, 0); clrtoeol();

    terminal_validate_input(input, world);

    return input;
}

void terminal_validate_input(Terminal_input input, World* world) {
    if (input.stStolpca >= 0 && input.stStolpca <= WORLD_ST_STOLPCEV - 1) {
        world->memo_tabela[(WORLD_ST_STOLPCEV - world->counterjiStolpcev[input.stStolpca] - 1) * 7 + (input.stStolpca)];
        terminal_spuscanje_zetona(&input, world);
    }

    if (input.stStolpca < 0 || input.stStolpca >= WORLD_ST_STOLPCEV)
        mvaddstr(10, 0, "Your input is invalid, please try again!");
}

int terminal_main(Terminal* terminal) {
    World world = world_new();

    while (1) {
        terminal_draw_world(terminal, &world);

        if (world.active) {
            break;
        }

        if (world.frames > 15) {
            world.active = 1;
        }

        //Terminal_input input = terminal_get_input(&world);
        terminal_get_input(&world);
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

    // Print out the help (to show you where the piece will drop)
    mvaddstr(maxY/ 2 - 5, 0, "The numbers below this line show you where your piece will drop!");
    for (int x = 0; x < world->width; ++x) {
        mvaddch(maxY / 2 - 3, x + maxX / 2 - 2, x + '0');
    }


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

void terminal_spuscanje_zetona(Terminal_input* input, World* world) {
    if (world->counterjiStolpcev[input->stStolpca] < WORLD_ST_VRSTIC) {
        world_popolnjenost_stolpcev(world, world->stolpci[input->stStolpca], world->counterjiStolpcev[input->stStolpca]++, input->stStolpca);

        int zaVnest = (world->frames % 2) ? 1 : 2;

        int x = input->stStolpca;
        int y = WORLD_ST_VRSTIC - (world->counterjiStolpcev[x]);

        world->memo_tabela[x][y] = zaVnest;

        char znak = (world->frames % 2) ? 'O' : 'X';

        Zeton zeton = zeton_new(input->stStolpca, WORLD_ST_VRSTIC - (world->counterjiStolpcev[input->stStolpca]), znak);
        world->zetoni[world->frames] = zeton; // dodelimo tabeli zetonov zeton

        world->frames++;
    } else {
        mvprintw(4, 0, "Column %d is already full! Please choose another one.", input->stStolpca);
    }
}
