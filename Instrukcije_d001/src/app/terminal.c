//
// Created by Edin on 15. 03. 2022.
//

#include "terminal.h"

void terminal_init() {
    initscr();
    curs_set(0);

    noecho();
    refresh();
}

Terminal terminal_new() {
    Terminal this;

    int y, x; getmaxyx(stdscr, y, x);

    this = (Terminal){
        .maxX = x,
        .maxY = y,
        .steviloPolja = 0
    };

    return this;
}

void terminal_validate_input(World* world, Terminal_input* input) {
    if (input->input >= 0 && input->input <= 8) { // input je veljaven
        if (world->memoTabela[input->x][input->y] != 1 && world->memoTabela[input->x][input->y] != 2) { // še mismo dodal sem
            world_poteza(world, world->memoTabela, input->input); // torej zgodila se je poteza
        } else { // input, ki je ze bil izbran
            mvaddstr(10, 0, "Your input has already been chosen, please try again!");
        }
    }

    if (input->input < 0 || input->input > 8)
        mvaddstr(10, 0, "Your input is invalid, please try again!");
}

Terminal_input terminal_get_input(World* world) {
    mvaddstr(0, 0, "Enter a number between 0 and 8 to add your piece:");
    int vnos = getch() - '0'; // read the players input

    Terminal_input input = terminal_input_new(vnos, vnos / WORLD_SIRINA_BOARDA, vnos % WORLD_SIRINA_BOARDA);

    mvaddch(0, 50, vnos + '0'); // za prikazat userjev input

    // to je za popucat napačne inpute (šele naslednjo iteracijo)
    move(10, 0); clrtoeol();

    terminal_validate_input(world, &input); // ta funkcija preveri, da je vse v redu in če ni, to izpiše

    return input;
}

Terminal_input terminal_input_new(int input, int x, int y) {
    Terminal_input this;

    this = (Terminal_input){
        .input = input,
        .x = x,
        .y = y
    };

    return this;
}

int terminal_main() {
    World world = world_new();

    while (1) {
        terminal_draw_world(&world);

        Terminal_input input = terminal_get_input(&world);

        if (world.active == 1)
            break;

        // (pri tem if-u moramo dati == 1, ker če ne bo tudi v primeru drawa razlicno od nic in bo slo v if in ne else if)
        if (world_dinamicnoPoisciZmagovalca(&world, input.x, input.y, (world.frames % 2 == 0) ? 1 : 2, world.memoTabela) == 1) {
            // We got a winner
            world.active = 1;
            mvprintw(8, 0, "Game over!\nPlayer %c has won the game!\nPress any key to exit.", (world.frames % 2 == 0) ? 'O' : 'X');
        } else if ((world_dinamicnoPoisciZmagovalca (&world, input.x, input.y, (world.frames % 2 == 0) ? 1 : 2, world.memoTabela) == 2) && world.active == 0) {
            // No one won, we got a draw
            mvaddstr(10, 0, "Game over! No one won. Press any key to exit.");
            move(0, 50);
            world.active = 1;
        }
    }

    if (get_platform_number() == 0) {
        system("cls");
    } else if (get_platform_number() == 1) {
        system("clear");
    }

    return 0;
}

void terminal_draw_world(World* world) {
    Terminal terminal = terminal_new();
    int maxY = terminal.maxY, maxX = terminal.maxX;

    mvaddstr(3, 8, "<--- to show you where X/O will drop (it'll drop in the middle)");
    mvaddstr(4, 13, "[X will start]");

    // Print out the helper matrix (to show where the piece will drop)
    for (int y = 0; y < world->height; ++y) {
        for (int x = 0; x < world->width; ++x) {
            mvaddch(y + 2, x + 2,  terminal.steviloPolja + '0');
            terminal.steviloPolja++;
        }
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
                    mvaddch(y + maxY / 2 - 1, x + maxX / 2 - 2, z->znak);
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
