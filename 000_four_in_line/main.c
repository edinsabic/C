#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int counter = 0; // stevec, da vemo kdo bo na vrsti
int stevecDvaDTabele = 0; // stevec za stevilo vseh potez

int checkVertical(int** dvaDTabela, int one) {
    for (int i = 0; i < 7; i++){
        if ((dvaDTabela[0][i] == one && dvaDTabela[1][i] == one && dvaDTabela[2][i] == one && dvaDTabela[3][i] == one))
            return 1;
        if ((dvaDTabela[1][i] == one && dvaDTabela[2][i] == one && dvaDTabela[3][i] == one && dvaDTabela[4][i] == one))
            return 1;
        if ((dvaDTabela[2][i] == one && dvaDTabela[3][i] == one && dvaDTabela[4][i] == one && dvaDTabela[5][i] == one))
            return 1;
    }

    return 0;
}

int checkHorizontal(int** dvaDTabela, int one) {
    for (int i = 0; i < 6; i++) {
        if ((dvaDTabela[i][0] == one && dvaDTabela[i][1] == one && dvaDTabela[i][2] == one && dvaDTabela[i][3] == one))
            return 1;
        if ((dvaDTabela[i][1] == one && dvaDTabela[i][2] == one && dvaDTabela[i][3] == one && dvaDTabela[i][4] == one))
            return 1;
        if ((dvaDTabela[i][2] == one && dvaDTabela[i][3] == one && dvaDTabela[i][4] == one && dvaDTabela[i][5] == one))
            return 1;
        if ((dvaDTabela[i][3] == one && dvaDTabela[i][4] == one && dvaDTabela[i][5] == one && dvaDTabela[i][6] == one))
            return 1;
    }
    return 0;
}

int checkDiagonal1(int** dvaDTabela, int one) {
    for (int i = 0; i < 6; i++) {
    	for (int j = 0; j < 7; j++) {
    		if (i < 3 && j < 4) {
    			if ((dvaDTabela[i][j] == one && dvaDTabela[i+1][j+1] == one && dvaDTabela[i+2][j+2] == one && dvaDTabela[i+3][j+3] == one))
            		return 1;
    		}
    	}
    }
    return 0;
}

int checkDiagonal2(int** dvaDTabela, int one) {
    for (int i = 0; i < 6; i++) {
    	for (int j = 0; j < 7; j++) {
    		if (i < 3 && j > 2) {
    			if ((dvaDTabela[i][j] == one && dvaDTabela[i+1][j-1] == one && dvaDTabela[i+2][j-2] == one && dvaDTabela[i+3][j-3] == one))
            		return 1;
    		}
    	}
    }
    return 0;
}

int isWin(int** dvaDTabela, int one, int two) {
	if (checkVertical(dvaDTabela, one) || checkVertical(dvaDTabela, two))
		return 1;
	if (checkHorizontal(dvaDTabela, one) || checkHorizontal(dvaDTabela, two))
		return 1;
	if (checkDiagonal1(dvaDTabela, one) || checkDiagonal1(dvaDTabela, two))
		return 1;
	if (checkDiagonal2(dvaDTabela, one) || checkDiagonal2(dvaDTabela, two))
		return 1;

	return 0;
}

WINDOW* novoPolje(int h, int w, int sy, int sx) {
	WINDOW* win = newwin(h, w, sy, sx); 
	box(win, '|', '-');

	return win;
}

void popolnjenostStolpcev(int* tabela, int stolpecCounter, int** dvaDTabela, int vrstica) {
	tabela[stolpecCounter] = (counter % 2 == 0) ? 1 : 2;

	dvaDTabela[stolpecCounter][vrstica - 1] = (counter % 2 == 0) ? 1 : 2;
	stevecDvaDTabele++;
}

void spuscanje_zetona(int c, int** stolpci, int* counterjiStolpcev, WINDOW** polja, int** dvaDTabela, int stVrstic, int stStolpcev) {
	if (counterjiStolpcev[c - 1] < stVrstic) {
		popolnjenostStolpcev(stolpci[c - 1], counterjiStolpcev[c - 1]++, dvaDTabela, c);

		   wbkgd(polja[(stStolpcev - counterjiStolpcev[c - 1] - 1) * 7 + (c - 1)], COLOR_PAIR((counter % 2 == 0) ? 1 : 2));
		wrefresh(polja[(stStolpcev - counterjiStolpcev[c - 1] - 1) * 7 + (c - 1)]);

		counter++;
	} else
		mvprintw(4, 0, "Column %d is already full! Please choose another one.", c);
}

int main() {
	initscr();
	curs_set(0);

	if (!has_colors()) { // we need to check this
		printw("Terminal does not support color");
		getch();
		return -1;
	}
	start_color();

	init_pair(1, COLOR_CYAN, COLOR_RED); // rdeči žeton
	init_pair(2, COLOR_CYAN, COLOR_BLUE); // modri žeton

	int yMax, xMax, stVrstic = 6, stStolpcev = 7;
	getmaxyx(stdscr, yMax, xMax);

	WINDOW** polja = (WINDOW**) malloc((stVrstic * stStolpcev) * sizeof(WINDOW*));

	int** dvaDTabela = (int**)calloc(sizeof(int*), stVrstic);
    for (int i = 0; i < stVrstic; i++)
        *(dvaDTabela + i) = (int*)calloc(sizeof(int), stStolpcev);

    int** stolpci = (int**)calloc(sizeof(int*), stStolpcev);
    for (int i = 0; i < stStolpcev; i++)
    	*(stolpci + i) = (int*)calloc(sizeof(int), stVrstic);

    int* counterjiStolpcev = (int*) malloc((stStolpcev) * sizeof(int));
	
	int h = yMax / 7, w = xMax / 7;
	
	refresh();

	for (int i = (stVrstic*stStolpcev)-1, j = 0; i >= 0, j < (stVrstic * stStolpcev); i--, j++) {
		polja[j] = novoPolje(h, w, yMax - (i / 7 + 1) * h, (j % 7) * w);
		wrefresh(polja[j]);
	}
	

	for (int i = 0; i < stStolpcev; i++) {
		mvprintw(8, ((i % 7) * w) + w/2, "%d", i + 1);
		refresh();
	}
	
	char str[80] = "Enter a number between 1 and 7 where you want to drop your piece in: ";
	mvprintw(0, 0, str);
	refresh();

	while (1) {
		if (isWin(dvaDTabela, 1, 2)) {
			char stringR[50] = "Game over! Red wins";
			char stringB[50] = "Game over! Blue wins";
			char exit[50] = "Press any key to exit";

			if (counter % 2 == 0)
				mvprintw(3, xMax/2 - strlen(stringB) / 2, stringB);
			else
				mvprintw(3, xMax/2 - strlen(stringR) / 2 - 1, stringR);	

			mvprintw(5, xMax/2 - strlen(exit) / 2 - 1, exit);

			break;
		}

		if (stevecDvaDTabele >= stVrstic * stStolpcev) {
			char str[100] = "Game over! Noone won the game. Press any key to exit";
			mvprintw(3, xMax/2 - strlen(str) / 2 - 1, str);
			break;
		}

		int c = getch() - '0';

		move(4, 0);
		clrtoeol();
		
		char zeton = (counter % 2 == 0) ? 'R' : 'B';

		if (c >= 0 && c <= 7)
			spuscanje_zetona(c, stolpci, counterjiStolpcev, polja, dvaDTabela, stVrstic, stStolpcev);
		else
			mvprintw(4, 0, "Your input is invalid, please try again!");

		move(0, strlen(str));
	}

	free(polja);

	for (int i = 0; i < stVrstic; i++)
    	free(dvaDTabela[i]);
	free(dvaDTabela);

	for (int i = 0; i < stStolpcev; i++)
		free(stolpci[i]);
	free(stolpci);

	free(counterjiStolpcev);

	getch();
	endwin();
	return 0;
}
