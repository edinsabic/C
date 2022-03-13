#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int counter = 0;
int igreJeKonec = 0;

WINDOW* novoOkno(int h, int w, int sy, int sx) {
	WINDOW* win = newwin(h, w, sy, sx); 
	box(win, '|', '-');

	return win;
}

void polje(int c, char zmagovalec, WINDOW** okna, int* memoizacijaPolja) {
	if (c >= 0 && c <= 9) {
		if (memoizacijaPolja[c - 1] == 1 || memoizacijaPolja[c - 1] == 2) {
			if (!igreJeKonec)
				mvprintw(3, 0, "You've selected and input that's already been chosen, please try again!");
			move(0, 52);
		} else {
			mvwprintw(okna[c - 1], 3, 6, "%c", zmagovalec);	
			memoizacijaPolja[c - 1] = (counter % 2 == 0) ? 1 : 2;
			move(0, 52);
			counter++;
		}
	} else {
		if (!igreJeKonec)
			mvprintw(3, 0, "Your input is invalid. Please try again!");
		move(0, 52);
	}
}

void zmagovalnaKombinacija(int x, int y, int z, int* memoizacijaPolja) {
	if ((memoizacijaPolja[x] > 0 && memoizacijaPolja[y] > 0 && memoizacijaPolja[z] > 0) && (memoizacijaPolja[x] == memoizacijaPolja[y])) {
		if (memoizacijaPolja[x] == memoizacijaPolja[z]) {
			igreJeKonec = 1;
			char winner = (counter % 2 == 0) ? 'O' : 'X';
			mvprintw(5, 0, "Game over!\nPlayer %c has won the game!\nPress any key to exit.", winner);
		}
		move(0,52);
	}
}

int main() {
	initscr();
	curs_set(0);

	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	WINDOW** okna = (WINDOW**) malloc(9 * sizeof(WINDOW*)); // free this!
	int* memoizacijaPolja = calloc(9, sizeof(int)); // free this!

	int h = ((yMax / 2) / 3), w = ((xMax / 2) / 3);

	WINDOW* win1 = novoOkno(h, w, (yMax / 4) + (0   /2/3) - 0, (xMax / 4) + (0   /2/3)); okna[0] = win1;
	WINDOW* win2 = novoOkno(h, w, (yMax / 4) + (0   /2/3) - 0, (xMax / 4) + (xMax/2/3)); okna[1] = win2;
	WINDOW* win3 = novoOkno(h, w, (yMax / 4) + (0   /2/3) - 0, (xMax / 4) + (xMax/1/3)); okna[2] = win3;
	WINDOW* win4 = novoOkno(h, w, (yMax / 4) + (yMax/2/3) - 0, (xMax / 4) + (0   /2/3)); okna[3] = win4;
	WINDOW* win5 = novoOkno(h, w, (yMax / 4) + (yMax/2/3) - 0, (xMax / 4) + (xMax/2/3)); okna[4] = win5;
	WINDOW* win6 = novoOkno(h, w, (yMax / 4) + (yMax/2/3) - 0, (xMax / 4) + (xMax/1/3)); okna[5] = win6;
	WINDOW* win7 = novoOkno(h, w, (yMax / 4) + (yMax/1/3) - 1, (xMax / 4) + (0   /2/3)); okna[6] = win7;
	WINDOW* win8 = novoOkno(h, w, (yMax / 4) + (yMax/1/3) - 1, (xMax / 4) + (xMax/2/3)); okna[7] = win8;
	WINDOW* win9 = novoOkno(h, w, (yMax / 4) + (yMax/1/3) - 1, (xMax / 4) + (xMax/1/3)); okna[8] = win9;

	mvprintw(0, 0, "Enter a number betwen 1 and 9 to enter your simbol: ");
	refresh();

	while (1) {
		for (int i = 0; i < 9; i++) {
			mvwprintw(okna[i], 1, 1, "[%d]", i + 1);
			wrefresh(okna[i]);
		}

		int c = getch() - '0';

		move(3, 0);
		clrtoeol();

		char zmagovalec = (counter % 2 == 0) ? 'X' : 'O';

		polje(c, zmagovalec, okna, memoizacijaPolja);
		
		if (igreJeKonec)
			break;

		zmagovalnaKombinacija(0, 1, 2, memoizacijaPolja);
		zmagovalnaKombinacija(3, 4, 5, memoizacijaPolja);
		zmagovalnaKombinacija(6, 7, 8, memoizacijaPolja);
		zmagovalnaKombinacija(0, 3, 6, memoizacijaPolja);
		zmagovalnaKombinacija(1, 4, 7, memoizacijaPolja);
		zmagovalnaKombinacija(0, 4, 8, memoizacijaPolja);
		zmagovalnaKombinacija(2, 4, 6, memoizacijaPolja);

		if (counter == 9) {
			mvprintw(7, 0, "Game over! Noone won. Press any key to exit.");
			move(0,52);
			igreJeKonec = 1;
		}

		refresh();
	}

	free(memoizacijaPolja);
	free(okna);

	endwin();
	return 0;
}