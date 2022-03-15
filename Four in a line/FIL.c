#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int counter = 0;
int stevecDvaDTabele = 0;

int checkVertical(int** dvaDTabela, int one) {
    for (int i = 0; i < 7; i++){
        if ((dvaDTabela[0][i] == one && dvaDTabela[1][i] == one && dvaDTabela[2][i] == one && dvaDTabela[3][i] == one)) {
            return 1;
        }
        if ((dvaDTabela[1][i] == one && dvaDTabela[2][i] == one && dvaDTabela[3][i] == one && dvaDTabela[4][i] == one)) {
            return 1;
        }
        if ((dvaDTabela[2][i] == one && dvaDTabela[3][i] == one && dvaDTabela[4][i] == one && dvaDTabela[5][i] == one)) {
            return 1;
        }
    }

    return 0;
}

int checkHorizontal(int** dvaDTabela, int one) {
    for (int i = 0; i < 6; i++) {
        if ((dvaDTabela[i][0] == one && dvaDTabela[i][1] == one && dvaDTabela[i][2] == one && dvaDTabela[i][3] == one)) {
            return 1;
        }
        if ((dvaDTabela[i][1] == one && dvaDTabela[i][2] == one && dvaDTabela[i][3] == one && dvaDTabela[i][4] == one)) {
            return 1;
        }
        if ((dvaDTabela[i][2] == one && dvaDTabela[i][3] == one && dvaDTabela[i][4] == one && dvaDTabela[i][5] == one)) {
            return 1;
        }
        if ((dvaDTabela[i][3] == one && dvaDTabela[i][4] == one && dvaDTabela[i][5] == one && dvaDTabela[i][6] == one)) {
            return 1;
        }
    }
    return 0;
}

int checkDiagonal1(int** dvaDTabela, int one) {
    for (int i = 0; i < 6; i++) {
    	for (int j = 0; j < 7; j++) {
    		if (i < 3 && j < 4) {
    			if ((dvaDTabela[i][j] == one && dvaDTabela[i+1][j+1] == one && dvaDTabela[i+2][j+2] == one && dvaDTabela[i+3][j+3] == one)) {
            		return 1;
        		}
    		}
    	}
    }
    return 0;
}

int checkDiagonal2(int** dvaDTabela, int one) {
    for (int i = 0; i < 6; i++) {
    	for (int j = 0; j < 7; j++) {
    		if (i < 3 && j > 2) {
    			if ((dvaDTabela[i][j] == one && dvaDTabela[i+1][j-1] == one && dvaDTabela[i+2][j-2] == one && dvaDTabela[i+3][j-3] == one)) {
            		return 1;
        		}
    		}
    	}
    }
    return 0;
}
/*
*/

int isWin(int** dvaDTabela, int one, int two) {
	if (checkVertical(dvaDTabela, one) || checkVertical(dvaDTabela, two)) {
		return 1;
	} 
	if (checkHorizontal(dvaDTabela, one) || checkHorizontal(dvaDTabela, two)) {
		return 1;
	}
	if (checkDiagonal1(dvaDTabela, one) || checkDiagonal1(dvaDTabela, two)) {
		return 1;
	}
	if (checkDiagonal2(dvaDTabela, one) || checkDiagonal2(dvaDTabela, two)) {
		return 1;
	}

	return 0;
}

WINDOW* novoPolje(int h, int w, int sy, int sx) {
	WINDOW* win = newwin(h, w, sy, sx); 
	box(win, '|', '-');

	return win;
}

void popolnjenostStolpcev(int* tabela, int stolpecCounter, int** dvaDTabela, int vrstica) {
	int vnesena = (counter % 2 == 0) ? 1 : 2;
	tabela[stolpecCounter] = vnesena;

	dvaDTabela[stolpecCounter][vrstica-1] = vnesena;
	stevecDvaDTabele++;
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

	WINDOW** polja = (WINDOW**) malloc((stStolpcev * stStolpcev) * sizeof(WINDOW*)); // free this!
	//int** vsiStolpci = (int**)calloc()

	int our2Darray[6][7];

	int** dvaDTabela = (int**)calloc(sizeof(int*), 6);
    for(int i=0; i < 6; i++)
        *(dvaDTabela+i) = (int*)calloc(sizeof(int), 7);

	int* stolpec1 = (int*)calloc(stVrstic, sizeof(int)); // free this
	int* stolpec2 = (int*)calloc(stVrstic, sizeof(int)); // free this
	int* stolpec3 = (int*)calloc(stVrstic, sizeof(int)); // free this
	int* stolpec4 = (int*)calloc(stVrstic, sizeof(int)); // free this
	int* stolpec5 = (int*)calloc(stVrstic, sizeof(int)); // free this
	int* stolpec6 = (int*)calloc(stVrstic, sizeof(int)); // free this
	int* stolpec7 = (int*)calloc(stVrstic, sizeof(int)); // free this
	
	int h = yMax / 7, w = xMax / 7;
	
	refresh();

	
	/*
	for (int i = 0; i < stVrstic * stStolpcev; i++) {
		polja[i] = novoPolje(h, w, yMax - (i / 7 + 1) * h, (i % 7) * w);
		//mvwprintw(polja[i], 1,1, "%d %d %d", i, yMax - ((i%7)*6), (i % 7) * w);
		mvwprintw(polja[i], 1,1, "%d %d %d", i, yMax - (i / 7 + 1) * h, (i % 7) * w);
		wrefresh(polja[i]);
	}
	*/

	for (int i = (stVrstic*stStolpcev)-1, j = 0; i >= 0, j < (stVrstic*stStolpcev); i--, j++) {
		polja[j] = novoPolje(h, w, yMax - (i / 7 + 1) * h, (j % 7) * w);
		// mvwprintw(polja[j], 1,1, "%d %d %d", j, yMax - (i / 7 + 1) * h, (i % 7) * w);
		wrefresh(polja[j]);
	}
	

	for (int i = 0; i < stStolpcev; i++) {
		mvprintw(8, i + (w/2) + (10 * i), "%d", i+1);
		refresh();
	}
	
	char str[80] = "Enter a number between 1 and 7 where you want to drop your piece in: ";
	mvprintw(0, 0, str);
	refresh();

	int stolpec1Counter = 0;
	int stolpec2Counter = 0;
	int stolpec3Counter = 0;
	int stolpec4Counter = 0;
	int stolpec5Counter = 0;
	int stolpec6Counter = 0;
	int stolpec7Counter = 0;

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

		if (stevecDvaDTabele >= 42) {
			char str[100] = "Game over! Noone won the game. Press any key to exit";
			mvprintw(3, xMax/2 - strlen(str) / 2 - 1, str);
			break;
		}

		int c = getch() - '0';

		move(4, 0);
		clrtoeol();
		
		char zeton = (counter % 2 == 0) ? 'R' : 'B';

		//wbkgd je treba popraut samo polje

		if (c == 1) {
			if (stolpec1Counter < stVrstic) {
				popolnjenostStolpcev(stolpec1, stolpec1Counter++, dvaDTabela, c);
				//mvwprintw(polja[(stStolpcev - stolpec1Counter-1)*7], 1, 1, "%c", zeton);
				if (counter % 2 == 0)
					wbkgd(polja[(stStolpcev - stolpec1Counter-1)*7], COLOR_PAIR(1));
				else
					wbkgd(polja[(stStolpcev - stolpec1Counter-1)*7], COLOR_PAIR(2));
				wrefresh(polja[(stStolpcev - stolpec1Counter-1)*7]);

				counter++;
			} else {
				mvprintw(4, 0, "Column %d is already full! Please choose another one.", c);
			}
		} else if (c == 2) {
			if (stolpec2Counter < stVrstic) {
				popolnjenostStolpcev(stolpec2, stolpec2Counter++, dvaDTabela, c);
				//mvwprintw(polja[(stStolpcev - stolpec2Counter-1)*7+(c-1)], 1, 1, "%c", zeton);
				if (counter % 2 == 0)
					wbkgd(polja[(stStolpcev - stolpec2Counter-1)*7+(c-1)], COLOR_PAIR(1));
				else
					wbkgd(polja[(stStolpcev - stolpec2Counter-1)*7+(c-1)], COLOR_PAIR(2));
				wrefresh(polja[(stStolpcev - stolpec2Counter-1)*7+(c-1)]);

				counter++;
			} else {
				mvprintw(4, 0, "Column %d is already full! Please choose another one.", c);
			}
		} else if (c == 3) {
			if (stolpec3Counter < stVrstic) {
				popolnjenostStolpcev(stolpec3, stolpec3Counter++, dvaDTabela, c);
				//mvwprintw(polja[(stStolpcev - stolpec3Counter-1)*7+(c-1)], 1, 1, "%c", zeton);
				if (counter % 2 == 0)
					wbkgd(polja[(stStolpcev - stolpec3Counter-1)*7+(c-1)], COLOR_PAIR(1));
				else
					wbkgd(polja[(stStolpcev - stolpec3Counter-1)*7+(c-1)], COLOR_PAIR(2));
				wrefresh(polja[(stStolpcev - stolpec3Counter-1)*7+(c-1)]);

				counter++;
			} else {
				mvprintw(4, 0, "Column %d is already full! Please choose another one.", c);
			}
		} else if (c == 4) {
			if (stolpec4Counter < stVrstic) {
				popolnjenostStolpcev(stolpec4, stolpec4Counter++, dvaDTabela, c);
				//mvwprintw(polja[(stStolpcev - stolpec4Counter-1)*7+(c-1)], 1, 1, "%c", zeton);
				if (counter % 2 == 0)
					wbkgd(polja[(stStolpcev - stolpec4Counter-1)*7+(c-1)], COLOR_PAIR(1));
				else
					wbkgd(polja[(stStolpcev - stolpec4Counter-1)*7+(c-1)], COLOR_PAIR(2));
				wrefresh(polja[(stStolpcev - stolpec4Counter-1)*7+(c-1)]);

				counter++;
			} else {
				mvprintw(4, 0, "Column %d is already full! Please choose another one.", c);
			}
		} else if (c == 5) {
			if (stolpec5Counter < stVrstic) {
				popolnjenostStolpcev(stolpec6, stolpec5Counter++, dvaDTabela, c);
				//mvwprintw(polja[(stStolpcev - stolpec6Counter-1)*7+(c-1)], 1, 1, "%c", zeton);
				if (counter % 2 == 0)
					wbkgd(polja[(stStolpcev - stolpec5Counter-1)*7+(c-1)], COLOR_PAIR(1));
				else
					wbkgd(polja[(stStolpcev - stolpec5Counter-1)*7+(c-1)], COLOR_PAIR(2));
				wrefresh(polja[(stStolpcev - stolpec5Counter-1)*7+(c-1)]);

				counter++;
			} else {
				mvprintw(4, 0, "Column %d is already full! Please choose another one.", c);
			}
		} else if (c == 6) {
			if (stolpec6Counter < stVrstic) {
				popolnjenostStolpcev(stolpec6, stolpec6Counter++, dvaDTabela, c);
				//mvwprintw(polja[(stStolpcev - stolpec6Counter-1)*7+(c-1)], 1, 1, "%c", zeton);
				if (counter % 2 == 0)
					wbkgd(polja[(stStolpcev - stolpec6Counter-1)*7+(c-1)], COLOR_PAIR(1));
				else
					wbkgd(polja[(stStolpcev - stolpec6Counter-1)*7+(c-1)], COLOR_PAIR(2));
				wrefresh(polja[(stStolpcev - stolpec6Counter-1)*7+(c-1)]);

				counter++;
			} else {
				mvprintw(4, 0, "Column %d is already full! Please choose another one.", c);
			}
		} else if (c == 7) {
			if (stolpec7Counter < stVrstic) {
				popolnjenostStolpcev(stolpec7, stolpec7Counter++, dvaDTabela, c);
				//mvwprintw(polja[(stStolpcev - stolpec7Counter-1)*7+(c-1)], 1, 1, "%c", zeton);
				if (counter % 2 == 0)
					wbkgd(polja[(stStolpcev - stolpec7Counter-1)*7+(c-1)], COLOR_PAIR(1));
				else
					wbkgd(polja[(stStolpcev - stolpec7Counter-1)*7+(c-1)], COLOR_PAIR(2));
				wrefresh(polja[(stStolpcev - stolpec7Counter-1)*7+(c-1)]);

				counter++;
			} else {
				mvprintw(4, 0, "Column %d is already full! Please choose another one.", c);
			}
		} else {
			mvprintw(4, 0, "Your input is invalid, please try again!");
		}

		//mvprintw(2, 0, "%d", c);
		move(0, strlen(str));
	}

	/*

	for (int i = 0; i < stVrstic; i++) {
		mvprintw((7-i), 6, "%d", stolpec1[i]);
		mvprintw((7-i), 17, "%d", stolpec2[i]);
		mvprintw((7-i), 28, "%d", stolpec3[i]);
		mvprintw((7-i), 39, "%d", stolpec4[i]);
		mvprintw((7-i), 60, "%d", stolpec6[i]);
		mvprintw((7-i), 61, "%d", stolpec6[i]);
		mvprintw((7-i), 72, "%d", stolpec7[i]);
		
		refresh();
	}

	for (int i = 0; i < stVrstic; i++) {
		for (int j = 0; j < stStolpcev; j++) {
			mvprintw((7-i), j*10 + 1, "our: %d", dvaDTabela[i][j]);
		}
	}
	*/

	free(polja);

	getch();
	endwin();
	return 0;
}
