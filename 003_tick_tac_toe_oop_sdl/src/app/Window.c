#include <string.h>
#include <SDL.h>
#include "Window.h"


Window window_new(int width, int height){
	Window this = {
		.width = width,
		.height = height,
		.background = color_black(),
	};
	return this;
}

void window_init(Window* this, const char* title){
    SDL_Init(SDL_INIT_EVERYTHING);

    this->instance = SDL_CreateWindow(
			title,
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			this->width,
			this->height,
			SDL_WINDOW_SHOWN
		);

    this->renderer = SDL_CreateRenderer(this->instance,1, 0);

		Color c = this->background;
    SDL_SetRenderDrawColor(this->renderer, 0, c.r, c.g, c.b);

    SDL_RenderClear(this->renderer);
    SDL_RenderPresent(this->renderer);
}

void window_close(Window* this) {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->instance);
    SDL_Quit();
}