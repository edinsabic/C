
#ifndef _DOMAIN_BOARD
#define _DOMAIN_BOARD

#include <stdbool.h>

#include "Token.h"

typedef struct Board {
  int width;
  int height;
  Token tokens[100];
  int num_tokens;
} Board;

Board board_new(int height, int width);
void board_reset(Board* this);
bool board_full(Board* this);
Token_type board_player_won(Board* this);
void board_add_token(Board* this, int x, int y);
Token* board_get_token(Board* this, int x, int y);

#endif
