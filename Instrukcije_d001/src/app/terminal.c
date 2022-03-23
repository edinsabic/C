//
// Created by Edin on 15. 03. 2022.
//

#include "terminal.h"
#include <curses.h>
#include <string.h>
#include <stdlib.h>

int stevec = 0; // counter za to kdo bo na vrsti (X ali 0 za barvo)
int igreJeKonec = 0;

void terminal_init() {
    initscr();
    curs_set(0);

    noecho();
    refresh();
}

void jeKdoZmagal(int tabela[ST_ZMAGOVALNIH_KOMBINACIJ][3], int memoTabela[WORLD_ST_ZETONOV]) {
    for (int i = 0; i < 7; ++i) {
        if ((memoTabela[tabela[i][0]] > 0 && memoTabela[tabela[i][1]] > 0 && memoTabela[tabela[i][2]] > 0) && (memoTabela[tabela[i][0]] == memoTabela[tabela[i][1]]) && (memoTabela[tabela[i][0]] == memoTabela[tabela[i][2]])) {
            igreJeKonec = 1;
            char winner = (stevec % 2 == 0) ? 'O' : 'X';
            mvprintw(8, 0, "Game over!\nPlayer %c has won the game!\nPress any key to exit.", winner);
        }
    }
}

void poteza(World* world, int c, int* memoTabela) {
    int zaVnest = (stevec % 2) ? 1 : 2;
    memoTabela[c] = zaVnest;

    char XorO = (stevec % 2) ? 'O' : 'X';

    Zeton zeton = zeton_new(c % 3, c / 3, XorO);
    world->zetoni[stevec] = zeton; // dodelimo tabeli zetonov zeton

    stevec++;
}

int terminal_main() {
    World world = world_new();

    int* memoTabela = (int*) calloc(WORLD_ST_ZETONOV, sizeof(int));

    while (1) {
        terminal_draw_world(&world);

        char string[100]; // I used this way of working with strings
        strcpy(string, "Enter a number between 0 and 8 to add your piece:");
        mvaddstr(0, 0, string);

        int c = getch() - '0'; // read the players input

        mvaddch(0, strlen(string) + 1, c + '0'); // za prikazat userjev input

        // te tri so za popucat napačne inpute (šele naslednjo iteracijo)
        move(3, 0); clrtoeol();
        move(10, 0); clrtoeol();
        move(12, 0); clrtoeol();

        if (c < 0 || c > 8) {
            mvaddstr(10, 0, "Your input is invalid, please try again!");
        } else {
            if (memoTabela[c] != 1) { // še mismo dodal sem
                poteza(&world, c, memoTabela);
            } else {
                mvaddstr(12, 0, "Your input has already been chosen, please try again");
            }
        }

        if (igreJeKonec)
            break;

        int zmagovalneKombinacije[7][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{0,4,8},{2,4,6}};

        jeKdoZmagal(zmagovalneKombinacije, memoTabela);

        if (stevec == 9 && !igreJeKonec) {
            mvaddstr(7, 0, "Game over! No one won. Press any key to exit.");
            move(0, strlen(string) + 1);
            igreJeKonec = 1;
        }
    }

    system("clear"); // za popucat terminal

    return 0;
}

void terminal_draw_helperWorld(World* world) {
    mvaddstr(3, 8, "<--- to show you where X/O will drop (it'll drop in the middle)");
    mvaddstr(4, 13, "[X will start]");

    int counter = 0;
    for (int y = 0; y < world->height; ++y) {
        for (int x = 0; x < world->width; ++x) {
            mvaddch(y + 2, x + 2,  counter + '0');
            counter++;
        }
    }
}

void terminal_draw_world(World* world) {
    int maxY, maxX;
    getmaxyx(stdscr, maxY, maxX);

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
                    mvaddch(y + maxY / 2 - 1, x + maxX / 2 - 2, z->XorO);
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
