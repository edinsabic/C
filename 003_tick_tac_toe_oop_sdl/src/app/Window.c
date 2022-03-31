
#include "Window.h"

#include <SDL.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "Board.h"

Window window_new(int width, int height) {
  Window this = {
    .width = width, // this is test
    .height = height, // this
    .color_background = &COLOR_BLACK,
    .color_lines = &COLOR_WHITE
  };
  return this;
}

void window_init(Window* this, const char* title) {
  SDL_Init(SDL_INIT_EVERYTHING);

  this->instance = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->width, this->height, SDL_WINDOW_SHOWN);
  this->renderer = SDL_CreateRenderer(this->instance, 1, 0);
}

void window_main(Window* this) {
  Board board = board_new(3, 3);

  while (true) {
    _window_process_events(this, &board);
    _window_draw(this, &board);
    if (board_full(&board)) {
      SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "GAME WON", "Nobody won :(", this->instance);
      board_reset(&board);
    }
  }
}

void _window_process_events(Window* this, Board* board) {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        window_close(this);

      case SDL_MOUSEBUTTONDOWN:
        _window_on_mouse_click(this, board, event);
        Token_type token_type = board_player_won(board);
        if (token_type != TOKEN_NULL) {
          char buffer[1024];
          snprintf(buffer, sizeof(buffer), "Player %s won!", token_type_name(token_type));
          _window_draw(this, board);
          SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "GAME WON", buffer, this->instance);
          board_reset(board);
        }
    }
  }
}

void _window_on_mouse_click(Window* this, Board* board, SDL_Event event) {
  SDL_MouseButtonEvent e = event.button;
  int dx = this->width / board->width;
  int dy = this->height / board->height;
  int x = e.x / dx;
  int y = e.y / dy;
  board_add_token(board, x, y);
}

void _window_draw(Window* this, Board* board) {
  Color* c = this->color_background;
  SDL_SetRenderDrawColor(this->renderer, c->r, c->g, c->b, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(this->renderer);

  int dx = this->width / board->width;
  int dy = this->height / board->height;
  int DX = this->width / 15;
  int DY = this->height / 15;

  c = this->color_lines;
  SDL_SetRenderDrawColor(this->renderer, c->r, c->g, c->b, SDL_ALPHA_OPAQUE);
  for (int i = 1; i < 3; i++) {
    int x = i * dx;
    int y = i * dy;
    SDL_RenderDrawLine(this->renderer, DX, y, this->width - DX, y);
    SDL_RenderDrawLine(this->renderer, x, DY, y, this->height - DY);
  }

  for (int i = 0; i < board->num_tokens; i++) {
    Token token = board->tokens[i];
    // TODO: c = token.color;
    // TODO: SDL_SetRenderDrawColor(this->renderer, c->r, c->g, c->b, SDL_ALPHA_OPAQUE);
    switch (token.type) {
      case TOKEN_CIRCLE:
        _window_render_circle(this, dx * token.x + dx / 2, dy * token.y + dy / 2, DX);
        break;
      case TOKEN_CROSS:
        _window_render_cross(this, dx * token.x + dx / 2, dy * token.y + dy / 2, DX);
        break;
    }
  }

  SDL_RenderPresent(this->renderer);
}

void _window_render_cross(Window* this, int x, int y, int radius) {
  double c = (double)radius;
  int dxy = (int)sqrt(c * c / 2.0);
  SDL_RenderDrawLine(this->renderer, x - dxy, y - dxy, x + dxy, y + dxy);
  SDL_RenderDrawLine(this->renderer, x - dxy, y + dxy, x + dxy, y - dxy);
}

void _window_render_circle(Window* this, int x, int y, int radius) {
  int offsetx, offsety, d;
  int status;

  offsetx = 0;
  offsety = radius;
  d = radius - 1;
  status = 0;

  while (offsety >= offsetx) {
    status += SDL_RenderDrawPoint(this->renderer, x + offsetx, y + offsety);
    status += SDL_RenderDrawPoint(this->renderer, x + offsety, y + offsetx);
    status += SDL_RenderDrawPoint(this->renderer, x - offsetx, y + offsety);
    status += SDL_RenderDrawPoint(this->renderer, x - offsety, y + offsetx);
    status += SDL_RenderDrawPoint(this->renderer, x + offsetx, y - offsety);
    status += SDL_RenderDrawPoint(this->renderer, x + offsety, y - offsetx);
    status += SDL_RenderDrawPoint(this->renderer, x - offsetx, y - offsety);
    status += SDL_RenderDrawPoint(this->renderer, x - offsety, y - offsetx);

    if (status < 0) {
      status = -1;
      break;
    }

    if (d >= 2 * offsetx) {
      d -= 2 * offsetx + 1;
      offsetx += 1;
    } else if (d < 2 * (radius - offsety)) {
      d += 2 * offsety - 1;
      offsety -= 1;
    } else {
      d += 2 * (offsety - offsetx - 1);
      offsety -= 1;
      offsetx += 1;
    }
  }
}

void window_close(Window* this) {
  SDL_DestroyRenderer(this->renderer);
  SDL_DestroyWindow(this->instance);
  SDL_Quit();
}