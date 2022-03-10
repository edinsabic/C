#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

// working without any functions, fix that

int main() {
	initscr();
	curs_set(0);

	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	//      win  = newwin(height, width, start_y, start_x);
	int height, width, start_y, start_x;
	/*
	height = yMax / 2; width = xMax / 2; start_y = yMax / 4; start_x = xMax / 4;
	WINDOW* win  = newwin(height, width, start_y, start_x); box(win, '|', ' ');
	*/

	height = (yMax / 2) / 3; width = (xMax / 2) / 3; start_y = yMax / 4; start_x = xMax / 4;
	WINDOW* win1 = newwin(height, width, start_y, start_x); box(win1, '|', '-');

	height = (yMax / 2) / 3; width = (xMax / 2) / 3; start_y = yMax / 4; start_x = (xMax / 4) + (xMax/2/3);
	WINDOW* win2 = newwin(height, width, start_y, start_x); box(win2, '|', '-');

	height = (yMax / 2) / 3; width = (xMax / 2) / 3; start_y = yMax / 4; start_x = (xMax / 4) + (xMax/1/3);
	WINDOW* win3 = newwin(height, width, start_y, start_x); box(win3, '|', '-');

	height = (yMax / 2) / 3; width = (xMax / 2) / 3; start_y = (yMax / 4) + (yMax/2/3); start_x = xMax / 4;
	WINDOW* win4 = newwin(height, width, start_y, start_x); box(win4, '|', '-');

	height = (yMax / 2) / 3; width = (xMax / 2) / 3; start_y = (yMax / 4) + (yMax/2/3); start_x = (xMax / 4) + (xMax/2/3);
	WINDOW* win5 = newwin(height, width, start_y, start_x); box(win5, '|', '-');

	height = (yMax / 2) / 3; width = (xMax / 2) / 3; start_y = (yMax / 4) + (yMax/2/3); start_x = (xMax / 4) + (xMax/1/3);
	WINDOW* win6 = newwin(height, width, start_y, start_x); box(win6, '|', '-');

	height = (yMax / 2) / 3; width = (xMax / 2) / 3; start_y = (yMax / 4) + (yMax/1/3) - 1; start_x = xMax / 4;
	WINDOW* win7 = newwin(height, width, start_y, start_x); box(win7, '|', '-');

	height = (yMax / 2) / 3; width = (xMax / 2) / 3; start_y = (yMax / 4) + (yMax/1/3) - 1; start_x = (xMax / 4) + (xMax/2/3);
	WINDOW* win8 = newwin(height, width, start_y, start_x); box(win8, '|', '-');

	height = (yMax / 2) / 3; width = (xMax / 2) / 3; start_y = (yMax / 4) + (yMax/1/3) - 1; start_x = (xMax / 4) + (xMax/1/3);
	WINDOW* win9 = newwin(height, width, start_y, start_x); box(win9, '|', '-');

	mvprintw(0, 0, "Enter a number betwen 1 and 9 to enter your simbol: ");
	refresh();

	int counter = 0;

	char xALIo = ' ';
	int* memo = calloc(9, sizeof(int)); // free this!
	// int memo[9]; // tabela za preverjanje zasedenosti polj - malloc this and free it later
	int igreJeKonec = 0;

	while (1) {

		mvwprintw(win1, 1, 1, "[1]");
		mvwprintw(win2, 1, 1, "[2]");
		mvwprintw(win3, 1, 1, "[3]");
		mvwprintw(win4, 1, 1, "[4]");
		mvwprintw(win5, 1, 1, "[5]");
		mvwprintw(win6, 1, 1, "[6]");
		mvwprintw(win7, 1, 1, "[7]");
		mvwprintw(win8, 1, 1, "[8]");
		mvwprintw(win9, 1, 1, "[9]");

		wrefresh(win1);
		wrefresh(win2);
		wrefresh(win3);
		wrefresh(win4);
		wrefresh(win5);
		wrefresh(win6);
		wrefresh(win7);
		wrefresh(win8);
		wrefresh(win9);

		int c = getch() - '0';

		move(3, 0);
		clrtoeol();

		if (counter % 2 == 0) {
			xALIo = 'X';
		} else {
			xALIo = 'O';
		}


		if (c == 1) {
			if (memo[c - 1] == 1 || memo[c - 1] == 2) {
				if (!igreJeKonec) {
					mvprintw(3, 0, "You've selected and input that's already been chosen, please try again!");
				}
				move(0, 52);
			} else {
				mvwprintw(win1, 3, 6, "%c", xALIo);	
				if (counter % 2 == 0) {
					memo[0] = 1;
				} else {
					memo[0] = 2;
				}
				move(0, 52);
				counter++;
			}
		} else if (c == 2) {
			if (memo[c - 1] == 1 || memo[c - 1] == 2) {
				if (!igreJeKonec)
					mvprintw(3, 0, "You've selected and input that's already been chosen, please try again!");
				move(0, 52);
			} else {
				mvwprintw(win2, 3, 6, "%c", xALIo);	
				if (counter % 2 == 0) {
					memo[1] = 1;
				} else {
					memo[1] = 2;
				}
				move(0, 52);
				counter++;
			}
		} else if (c == 3) {
			if (memo[c - 1] == 1 || memo[c - 1] == 2) {
				if (!igreJeKonec)
					mvprintw(3, 0, "You've selected and input that's already been chosen, please try again!");
				move(0, 52);
			} else {
				mvwprintw(win3, 3, 6, "%c", xALIo);	
				if (counter % 2 == 0) {
					memo[2] = 1;
				} else {
					memo[2] = 2;
				}
				move(0, 52);
				counter++;
			}
		} else if (c == 4) {
			if (memo[c - 1] == 1 || memo[c - 1] == 2) {
				if (!igreJeKonec)
					mvprintw(3, 0, "You've selected and input that's already been chosen, please try again!");
				move(0, 52);
			} else {
				mvwprintw(win4, 3, 6, "%c", xALIo);	
				if (counter % 2 == 0) {
					memo[3] = 1;
				} else {
					memo[3] = 2;
				}
				move(0, 52);
				counter++;
			}
		} else if (c == 5) {
			if (memo[c - 1] == 1 || memo[c - 1] == 2) {
				if (!igreJeKonec)
					mvprintw(3, 0, "You've selected and input that's already been chosen, please try again!");
				move(0, 52);
			} else {
				mvwprintw(win5, 3, 6, "%c", xALIo);	
				if (counter % 2 == 0) {
					memo[4] = 1;
				} else {
					memo[4] = 2;
				}
				move(0, 52);
				counter++;
			}
		} else if (c == 6) {
			if (memo[c - 1] == 1 || memo[c - 1] == 2) {
				if (!igreJeKonec)
					mvprintw(3, 0, "You've selected and input that's already been chosen, please try again!");
				move(0, 52);
			} else {
				mvwprintw(win6, 3, 6, "%c", xALIo);	
				if (counter % 2 == 0) {
					memo[5] = 1;
				} else {
					memo[5] = 2;
				}
				move(0, 52);
				counter++;
			}
		} else if (c == 7) {
			if (memo[c - 1] == 1 || memo[c - 1] == 2) {
				if (!igreJeKonec)
					mvprintw(3, 0, "You've selected and input that's already been chosen, please try again!");
				move(0, 52);
			} else {
				mvwprintw(win7, 3, 6, "%c", xALIo);	
				if (counter % 2 == 0) {
					memo[6] = 1;
				} else {
					memo[6] = 2;
				}
				move(0, 52);
				counter++;
			}
		} else if (c == 8) {
			if (memo[c - 1] == 1 || memo[c - 1] == 2) {
				if (!igreJeKonec)
					mvprintw(3, 0, "You've selected and input that's already been chosen, please try again!");
				move(0, 52);
			} else {
				mvwprintw(win8, 3, 6, "%c", xALIo);	
				if (counter % 2 == 0) {
					memo[7] = 1;
				} else {
					memo[7] = 2;
				}
				move(0, 52);
				counter++;
			}
		} else if (c == 9) {
			if (memo[c - 1] == 1 || memo[c - 1] == 2) {
				if (!igreJeKonec)
					mvprintw(3, 0, "You've selected and input that's already been chosen, please try again!");
				move(0, 52);
			} else {
				mvwprintw(win9, 3, 6, "%c", xALIo);	
				if (counter % 2 == 0) {
					memo[8] = 1;
				} else {
					memo[8] = 2;
				}
				move(0, 52);
				counter++;
			}
		} else {
			if (!igreJeKonec)
				mvprintw(3, 0, "Your input is invalid. Please try again!");
			move(0, 52);

		}
		
		if (igreJeKonec) {
			break;
		}

		if ((memo[0] > 0 && memo[1] > 0 && memo[2] > 0) && (memo[0] == memo[1])) {
			if (memo[0] == memo[2]) {
				igreJeKonec = 1;
				if (counter % 2 == 0) {
					mvprintw(5, 0, "Game over!\nPlayer %c has won the game!\nPress any key to exit.", 'O');
				} else {
					mvprintw(5, 0, "Game over!\nPlayer %c has won the game!\nPress any key to exit.", 'X');
				}
			}
			move(0,52);
		}
		if ((memo[3] > 0 && memo[4] > 0 && memo[5] > 0) && (memo[3] == memo[4])) {		
			if (memo[3] == memo[5]) {
				igreJeKonec = 1;
				if (counter % 2 == 0) {
					mvprintw(5, 0, "Game over!\nPlayer %c has won the game!\nPress any key to exit.", 'O');
				} else {
					mvprintw(5, 0, "Game over!\nPlayer %c has won the game!\nPress any key to exit.", 'X');
				}
			}
			move(0,52);
		}
		if ((memo[6] > 0 && memo[7] > 0 && memo[8] > 0) && (memo[6] == memo[7])) {
			if (memo[6] == memo[8]) {
				igreJeKonec = 1;
				if (counter % 2 == 0) {
					mvprintw(5, 0, "Game over!\nPlayer %c has won the game!\nPress any key to exit.", 'O');
				} else {
					mvprintw(5, 0, "Game over!\nPlayer %c has won the game!\nPress any key to exit.", 'X');
				}
			}
			move(0,52);
		}
		if ((memo[0] > 0 && memo[3] > 0 && memo[6] > 0) && (memo[0] == memo[3])) {
			if (memo[0] == memo[6]) {
				igreJeKonec = 1;
				if (counter % 2 == 0) {
					mvprintw(5, 0, "Game over!\nPlayer %c has won the game!\nPress any key to exit.", 'O');
				} else {
					mvprintw(5, 0, "Game over!\nPlayer %c has won the game!\nPress any key to exit.", 'X');
				}
			}
			move(0,52);
		}
		if ((memo[1] > 0 && memo[4] > 0 && memo[7] > 0) && (memo[1] == memo[4])) {
			if (memo[1] == memo[7]) {
				igreJeKonec = 1;
				if (counter % 2 == 0) {
					mvprintw(5, 0, "Game over!\nPlayer %c has won the game!\nPress any key to exit.", 'O');
				} else {
					mvprintw(5, 0, "Game over!\nPlayer %c has won the game!\nPress any key to exit.", 'X');
				}
			}
			move(0,52);
		}
		if ((memo[0] > 0 && memo[4] > 0 && memo[8] > 0) && (memo[0] == memo[4])) {
			if (memo[0] == memo[8]) {
				igreJeKonec = 1;
				if (counter % 2 == 0) {
					mvprintw(5, 0, "Game over!\nPlayer %c has won the game!\nPress any key to exit.", 'O');
				} else {
					mvprintw(5, 0, "Game over!\nPlayer %c has won the game!\nPress any key to exit.", 'X');
				}
			}
			move(0,52);
		}
		if ((memo[2] > 0 && memo[4] > 0 && memo[6] > 0) && (memo[2] == memo[4])) {
			if (memo[2] == memo[6]) {
				igreJeKonec = 1;
				if (counter % 2 == 0) {
					mvprintw(5, 0, "Game over!\nPlayer %c has won the game!\nPress any key to exit.", 'O');
				} else {
					mvprintw(5, 0, "Game over!\nPlayer %c has won the game!\nPress any key to exit.", 'X');
				}
			}
			move(0,52);
		}

		if (counter == 9) {
			mvprintw(7, 0, "Game over! Noben ni zmagal! Press any key to exit.");
			move(0,52);
			igreJeKonec = 1;
		}

		refresh();
	}

	free(memo);

	endwin();
	return 0;
}