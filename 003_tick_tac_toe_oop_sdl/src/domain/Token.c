#include "token.h"

Token token_new(int x, int y, Token_type type){

	Color color;
	if(token.type == TOKEN_CROSS) color = color_red();
	if(token.type == TOKEN_CROSS) color = color_blue();

	Token token = {
		.x = x,
		.y = y,
		.type = type,
		.color = color,
	};

	return token;
}