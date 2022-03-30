#include "Token.h"

Token token_new(int x, int y, Token_type token_type){

	Color color;
	if(token_type == TOKEN_CROSS) color = color_red();
	if(token_type == TOKEN_CROSS) color = color_blue();

	Token this = {
		.x = x,
		.y = y,
		.type = token_type,
		.color = color,
	};

	return this;
}