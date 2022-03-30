#ifndef _DOMAIN_TOKEN
#define _DOMAIN_TOKEN

#include "Color.h"

typedef enum Token_type {TOKEN_CIRCLE, TOKEN_CROSS, TOKEN_NULL} Token_type;

typedef struct Token {
	int x;
	int y;
	Token_type type;	
	Color color;
} Token;

Token token_new(int x, int y, Token_type type);

#endif