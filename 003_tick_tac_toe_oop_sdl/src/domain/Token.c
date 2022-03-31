#include "Token.h"

#include "Color.h"

Token token_new(int x, int y, Token_type token_type) {
  Color* color;
  if (token_type == TOKEN_CROSS) color = &COLOR_RED;
  if (token_type == TOKEN_CIRCLE) color = &COLOR_BLUE;

  Token this = {
    .x = x,
    .y = y,
    .type = token_type,
    .color = color,
  };

  return this;
}

char* token_type_name(Token_type type) {
  switch (type) {
    case TOKEN_CROSS: return "cross";
    case TOKEN_CIRCLE: return "circle";
  }
  return "NULL";
}
