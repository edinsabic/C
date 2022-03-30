#include "Board.h"
#include "bool.h"
#include "token.h"

Board board_new(int height, int width) {
	Board board = {
		.height = height,
		.width = width,
		.num_tokens = 0,
	};
	return board;
}

Token_type board_player_won(Board *board) {

	bool diagonal_cross_won = true;
	bool diagonal_circle_won = true;

	for (int y = 0; y < board->height; y++)
	{
		Token diagonal_token = board_get_token(board, y, y);
		if (!diagonal_token || token.type == TOKEN_CIRCLE) diagonal_cross_won = false;
		if (!diagonal_token || token.type == TOKEN_CROSS) diagonal_circle_won = false;

		bool horizontal_cross_won = true;
		bool horizontal_circle_won = true;
		bool vertical_cross_won = true;
		bool vertical_circle_won = true;
		
		for (int x = 0; x < board->width; x++) {
			Token horizontal_token = board_get_token(board, x, y);
			Token vertical_token = board_get_token(board, y, x);
			if (!horizontal_token || token.type == TOKEN_CIRCLE) horizontal_cross_won = false;
			if (!horizontal_token || token.type == TOKEN_CROSS) horizontal_circle_won = false;
			if (!vertical_token || token.type == TOKEN_CIRCLE) vertical_cross_won = false;
			if (!vertical_token || token.type == TOKEN_CROSS) vertical_circle_won = false;
		}

		if (horizontal_cross_won || vertical_cross_won) return TOKEN_CROSS;
		if (horizontal_circle_won || vertical_circle_won) return TOKEN_CIRCLE;
	}

	if (diagonal_cross_won) return TOKEN_CROSS;
	if (diagonal_circle_won) return TOKEN_CIRCLE;

	return TOKEN_NULL;
}

Token* board_get_token(Board* board, int x, int y) {
	for (int i = 0; i < board->num_tokens; i++)
		if (board->tokens[i].x == x && board->tokens[i].y == y)
			return &board->tokens[i];
	return null;
}

void board_add_token(Board *board, int x, int y) {
	Token* token = &board->tokens[board.num_tokens];
	token->x = x;
	token->y = y;
	if(board->num_tokens%2==0) token->type = TOKEN_CIRCLE;
	else token->type = TOKEN_CROSS;
	board->num_tokens++;
}