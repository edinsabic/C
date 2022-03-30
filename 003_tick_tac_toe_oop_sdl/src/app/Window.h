
#ifndef _APP_WINDOW 
#define _APP_WINDOW

#include <SDL.h>
#include "color.h"

typedef struct Window {
    SDL_Window* instance;
    SDL_Renderer* renderer;
		int width;
		int height;
		Color background;
} Window;

#endif