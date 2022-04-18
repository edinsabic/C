
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
    Board board = board_new(this->width, this->height); // spremeni po svoje

    int* lastTime = NULL;
    int* smer = -1;

    while (true) {
        _window_process_events(this, &board);
        _window_draw(this, &board);

        board_move_ball(&board, SDL_GetTicks(), &lastTime, &smer);

        // 60 Hz osveževanje, nared mal delaya, da zaustavljaš program
    }
}

void _window_process_events(Window* this, Board* board) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {        
        switch (event.type) {
            case SDL_QUIT:
                window_close(this);

            // Tega ne bom uporabljal, leave for now
            case SDL_MOUSEBUTTONDOWN:
                _window_on_mouse_click(this, board, event);

            case SDL_KEYDOWN:
                // Handle arrow keys
                switch(event.key.keysym.scancode) {
                    case SDL_SCANCODE_W:
                        _window_key_click(this, board, event, 0);
                        break;
                    case SDL_SCANCODE_S:
                        _window_key_click(this, board, event, 1);
                        break;
                    case SDL_SCANCODE_A:
                        // _window_key_click(this, board, event, 2);
                        break;
                    case SDL_SCANCODE_D:
                        // _window_key_click(this, board, event, 3);
                        break;
                    case SDL_SCANCODE_UP:
                        _window_key_click(this, board, event, 2);
                        break;
                    case SDL_SCANCODE_DOWN:
                        _window_key_click(this, board, event, 3);
                        break;
                    case SDL_SCANCODE_LEFT:
                        break;
                    case SDL_SCANCODE_RIGHT:
                        break;
                    default:
                        break;
                }                
        }
    }
}

void _window_key_click(Window* this, Board* board, SDL_Event event, int direction) {
    SDL_KeyboardEvent e = event.key;
    
    board_move_paddle(board, direction);
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

    SDL_Rect t = {
        .x = board->table.x,
        .y = board->table.y,
        .w = board->table.width,
        .h = board->table.height,
    };

    SDL_Rect n = {
        .x = board->net.x,
        .y = board->net.y,
        .w = board->net.width,
        .h = board->net.height,
    };

    SDL_Rect p1 = {
        .x = board->paddles[0].x,
        .y = board->paddles[0].y,
        .w = board->paddles[0].width,
        .h = board->paddles[0].height,
    };

    SDL_Rect p2 = {
        .x = board->paddles[1].x,
        .y = board->paddles[1].y,
        .w = board->paddles[1].width,
        .h = board->paddles[1].height,
    };

    SDL_Rect b = {
        .x = board->ball.x,
        .y = board->ball.y,
        .w = board->ball.width,
        .h = board->ball.height,
    };

    SDL_SetRenderDrawColor(this->renderer, 0, 255, 255, SDL_ALPHA_OPAQUE);

    SDL_RenderDrawRect(this->renderer, &t);
    SDL_RenderDrawRect(this->renderer, &n);
    SDL_RenderDrawRect(this->renderer, &p1);
    SDL_RenderDrawRect(this->renderer, &p2);
    SDL_RenderDrawRect(this->renderer, &b);

    SDL_RenderPresent(this->renderer);
}

void window_close(Window* this) {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->instance);
    SDL_Quit();
}