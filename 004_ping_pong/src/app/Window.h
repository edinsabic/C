
#ifndef _APP_WINDOW
#define _APP_WINDOW

#include "Board.h"
#include "Color.h"
#include <SDL.h>

typedef struct Window {
  SDL_Window* instance;
  SDL_Renderer* renderer;
  int width;
  int height;
  Color* color_background;
  Color* color_lines;
} Window;

Window window_new(int width, int height);
void window_main(Window* this);
void window_init(Window* this, const char* title);
void window_close(Window* this);

void _window_draw(Window* this, Board* board);
void _window_key_click(Window* this, Board* board, SDL_Event event, int direction);
void _window_on_mouse_click(Window* this, Board* board, SDL_Event event);
void _window_process_events(Window* this, Board* board);

#endif