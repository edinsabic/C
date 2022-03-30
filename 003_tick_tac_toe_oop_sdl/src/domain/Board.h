
#ifndef _DOMAIN_BOARD
#define _DOMAIN_BOARD

#include "Token.h"

tyedef struct Board {
	int width;
	int height;
	Token tokens[100];
	int num_tokens;
} Board;

Board board_new(int height, int width);
Token_type board_end_game(Board* board);
void board_add_token(Board* board, int x, int y);

#endif
