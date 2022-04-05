
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
    .color_background = &COLOR_BLACK
  };
  return this;
}

void window_init(Window* this, const char* title) {
  SDL_Init(SDL_INIT_EVERYTHING);

  this->instance = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->width, this->height, SDL_WINDOW_SHOWN);
  this->renderer = SDL_CreateRenderer(this->instance, 1, 0);
}

void window_main(Window* this) {
  Board board = board_new(); // spremeni po svoje

  while (true) {
    _window_process_events(this, &board);
    _window_draw(this, &board);
    // 60 Hz osveževanje, nared mal delaya, da zaustavljaš program
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
    }
  }
}

void _window_on_mouse_click(Window* this, Board* board, SDL_Event event) {
  SDL_MouseButtonEvent e = event.button;
  // e.x & e.y vse kar rabs
}

void _window_draw(Window* this, Board* board) {
  Color* c = this->color_background;
  SDL_SetRenderDrawColor(this->renderer, c->r, c->g, c->b, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(this->renderer); // pobrise celotn zaslon

  // na podlagi boarda narisi (for zanke, tokni, ...)

  SDL_RenderPresent(this->renderer);
}

void window_close(Window* this) {
  SDL_DestroyRenderer(this->renderer);
  SDL_DestroyWindow(this->instance);
  SDL_Quit();
}