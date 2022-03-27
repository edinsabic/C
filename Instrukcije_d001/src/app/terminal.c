//
// Created by Edin on 15. 03. 2022.
//

#include "terminal.h"

Terminal terminal_init() {
    initscr();
    curs_set(0);

    Terminal this;

    int y, x; getmaxyx(stdscr, y, x);

    this = (Terminal){.maxX = x, .maxY = y, .steviloPolja = 0};

    noecho();
    refresh();

    return this;
}

int terminal_main() {
    World world = world_new();
    Terminal terminal = terminal_init();

    while (1) {
        terminal_draw_world(&world);

        mvaddstr(0, 0, "Enter a number between 0 and 8 to add your piece:");
        terminal.input = getch() - '0'; // read the players input

        terminal_izpisi_in_pucanje(terminal.input);

        int x = terminal.input / SIRINA_BOARDA; // nadstropje memoTabela
        int y = terminal.input % SIRINA_BOARDA; // soba v nadstropju v memoTabela

        if (terminal.input >= 0 && terminal.input <= 8) { // input je veljaven
            if (world.memoTabela[x][y] != 1 && world.memoTabela[x][y] != 2) { // še mismo dodal sem
                poteza(&world, world.memoTabela, terminal.input); // torej zgodila se je poteza
            } else { // input, ki je ze bil izbran
                mvaddstr(10, 0, "Your input has already been chosen, please try again!");
            }
        }

        if (world.active == 1)
            break;

        // (pri tem if-u moramo dati == 1, ker če ne bo tudi v primeru drawa razlicno od nic in bo slo v if in ne else if)
        if (dinamicnoPoisciZmagovalca(x, y, (world.frames % 2 == 0) ? 1 : 2, world.memoTabela, &world) == 1) {
            // We got a winner
            world.active = 1;
            mvprintw(8, 0, "Game over!\nPlayer %c has won the game!\nPress any key to exit.", (world.frames % 2 == 0) ? 'O' : 'X');
        } else if ((dinamicnoPoisciZmagovalca (x, y, (world.frames % 2 == 0) ? 1 : 2, world.memoTabela, &world) == 2) && world.active == 0) {
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
    Terminal terminal = terminal_init();
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

void terminal_izpisi_in_pucanje(int input) {
    mvaddch(0, 50, input + '0'); // za prikazat userjev input

    // to je za popucat napačne inpute (šele naslednjo iteracijo)
    move(10, 0); clrtoeol();

    if (input < 0 || input > 8)
        mvaddstr(10, 0, "Your input is invalid, please try again!");
}

int get_platform_number() {
    return PLATFORM_NUMBER; // 0 - Windows, 1 - Linux
}
