#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

WINDOW* novoPolje(int h, int w, int sy, int sx) {
	WINDOW* win = newwin(h, w, sy, sx); 
	box(win, '|', '-');

	return win;
}

int main() {
	initscr();
	curs_set(0);

	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	WINDOW** polja = (WINDOW**) malloc(42 * sizeof(WINDOW*)); // free this!
	
	int h = yMax / 7, w = xMax / 7, sy = yMax / 7, sx = xMax / 7;
	
	refresh();

	for (int i = 0; i < 42; i++) {
		polja[i] = novoPolje(h, w, yMax - (i / 7 + 1) * sy, (i % 7) * sx);
		wrefresh(polja[i]);
	}
	
	free(polja);

	getch();
	endwin();
	return 0;
}
