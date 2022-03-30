#include <SDL.h>
#include <Window.h>


Window window_new(int width, int height){
	Window* window = {
    .window = null,
    .renderer = null,
		.width = width,
		.height = height,
		.background = color_black(),
	}
}

void window_init(Window* window, string title){
    SDL_Init(SDL_INIT_EVERYTHING);

    window->instance = SDL_CreateWindow(
			title,
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			window->width,
			window->height,
			SDL_WINDOW_SHOWN
		);

    window->renderer = SDL_CreateRenderer(window->instance,1, 0);

		Color c = window->background;
    SDL_SetRenderDrawColor(window->renderer, 0, c.r, c.g, c.b);

    SDL_RenderClear(window->renderer);
    SDL_RenderPresent(window->renderer);


}

void window_close(Window* window) {
    SDL_DestroyRenderer(window->renderer);
    SDL_DestroyWindow(window->instance);
    SDL_Quit();
}