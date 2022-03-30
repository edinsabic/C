#include <stdbool.h>
#include <stdio.h>

#include "Board.h"
#include "Token.h"

Board board_new(int height, int width) {
	Board this;
	this.height = height;
	this.width = width;
	this.num_tokens = 0;
	return this;
}

Token_type board_player_won(Board *this) {

	bool diagonal_cross_won = true;
	bool diagonal_circle_won = true;

	for (int y = 0; y < this->height; y++)
	{
		Token diagonal_token = board_get_token(this, y, y);
		if (diagonal_token == NULL || diagonal_token.type == TOKEN_CIRCLE) diagonal_cross_won = false;
		if (diagonal_token == NULL || diagonal_token.type == TOKEN_CROSS) diagonal_circle_won = false;

		bool horizontal_cross_won = true;
		bool horizontal_circle_won = true;
		bool vertical_cross_won = true;
		bool vertical_circle_won = true;
		
		for (int x = 0; x < this->width; x++) {
			Token horizontal_token = board_get_token(this, x, y);
			Token vertical_token = board_get_token(this, y, x);
			if (horizontal_token == NULL || horizontal_token.type == TOKEN_CIRCLE) horizontal_cross_won = false;
			if (horizontal_token == NULL || horizontal_token.type == TOKEN_CROSS) horizontal_circle_won = false;
			if (vertical_token == NULL || vertical_token.type == TOKEN_CIRCLE) vertical_cross_won = false;
			if (vertical_token == NULL || vertical_token.type == TOKEN_CROSS) vertical_circle_won = false;
		}

		if (horizontal_cross_won || vertical_cross_won) return TOKEN_CROSS;
		if (horizontal_circle_won || vertical_circle_won) return TOKEN_CIRCLE;
	}

	if (diagonal_cross_won) return TOKEN_CROSS;
	if (diagonal_circle_won) return TOKEN_CIRCLE;

	return TOKEN_NULL;
}

Token* board_get_token(Board* this, int x, int y) {
	for (int i = 0; i < this->num_tokens; i++)
		if (this->tokens[i].x == x && this->tokens[i].y == y)
			return &this->tokens[i];
	return NULL;
}

void board_add_token(Board *this, int x, int y) {
	Token* token = &this->tokens[this.num_tokens];
	token->x = x;
	token->y = y;
	if(this->num_tokens%2==0) token->type = TOKEN_CIRCLE;
	else token->type = TOKEN_CROSS;
	this->num_tokens++;
}