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

Terminal_input terminal_get_input(Plosca* plosca) {
    mvaddstr(0, 0, "Enter a number between 0 and 6 to add your piece:");
    int vnos = getch() - '0'; // read the players input

    Terminal_input input = terminal_input_new(vnos);

    mvaddch(0, 50, vnos + '0');

    terminal_validate_input(input, plosca);

    return input;
}

void terminal_validate_input(Terminal_input input, Plosca* plosca) {
    // to je za popucat napačne inpute (šele naslednjo iteracijo)
    move(10, 0); clrtoeol();
    move(4, 0); clrtoeol();

    if (input.stStolpca >= 0 && input.stStolpca <= PLOSCA_ST_STOLPCEV - 1) {
        plosca->memo_tabela[(PLOSCA_ST_STOLPCEV - plosca->counterjiStolpcev[input.stStolpca] - 1) * 7 + (input.stStolpca)];
        terminal_spuscanje_zetona(&input, plosca);
    }

    if ((input.stStolpca < 0 || input.stStolpca >= PLOSCA_ST_STOLPCEV) && !plosca->active)
        mvaddstr(10, 0, "Your input is invalid, please try again!");
}

int terminal_main(Terminal* terminal) {
    Plosca plosca = plosca_new();

    while (1) {
        terminal_draw_plosca(terminal, &plosca);

        if (plosca.active)
            break;

        if (plosca_is_win(&plosca)) {

            if (plosca.frames % 2 == 0)
                mvaddstr(3, 0, "Game over! X wins. Press any key to exit!");
            else
                mvaddstr(3, 0, "Game over! O wins. Press any key to exit!");

            plosca.active = true;
        }

        if (plosca.stevec2DTabele >= PLOSCA_ST_VRSTIC * PLOSCA_ST_STOLPCEV) {
            mvaddstr(3, 0, "Game over! No one won the game. Press any key to exit");
            plosca.active = true;
        }

        //Terminal_input input = terminal_get_input(&plosca);
        terminal_get_input(&plosca);
    }

    if (utils_get_platform_number() == 0) {
        system("cls");
    } else if (utils_get_platform_number() == 1) {
        system("clear");
    }

    return 0;
}

void terminal_draw_plosca(Terminal* terminal, Plosca* plosca) {
    int maxY = terminal->maxY;
    int maxX = terminal->maxX;

    // Print out the help (to show you where the piece will drop)
    mvaddstr(maxY/ 2 - 5, 0, "The numbers below this line show you where your piece will drop!");
    for (int x = 0; x < plosca->width; ++x) {
        mvaddch(maxY / 2 - 3, x + maxX / 2 - 2, x + '0');
    }

    for (int y = 0; y < plosca->height; ++y) {
        for (int x = 0; x < plosca->width; ++x) {
            int flag = 0;

            for (int i = 0; i < PLOSCA_ST_ZETONOV; ++i) {
                Zeton* z = &plosca->zetoni[i];
                if (!z->porabljen) {
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

void terminal_spuscanje_zetona(Terminal_input* input, Plosca* plosca) {
    if (plosca->counterjiStolpcev[input->stStolpca] < PLOSCA_ST_VRSTIC) {

        // popolnjenost stolpcev
        plosca->stolpci[input->stStolpca][plosca->counterjiStolpcev[input->stStolpca]] = plosca->counterjiStolpcev[input->stStolpca]++;

        int zaVnest = (plosca->frames % 2) ? 1 : 2;

        int vrstica = PLOSCA_ST_VRSTIC - (plosca->counterjiStolpcev[input->stStolpca]);
        int stolpec = input->stStolpca;

        plosca->memo_tabela[vrstica][stolpec] = zaVnest;

        char znak = (plosca->frames % 2) ? 'X' : 'O';

        Zeton zeton = zeton_new(stolpec, vrstica, znak);
        plosca->zetoni[plosca->frames] = zeton; // dodelimo tabeli zetonov zeton

        plosca->frames++;
    } else {
        mvprintw(4, 0, "Column %d is already full! Please choose another one.", input->stStolpca);
    }
}
