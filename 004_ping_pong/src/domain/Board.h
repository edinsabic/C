
#ifndef _DOMAIN_BOARD
#define _DOMAIN_BOARD

#define BOARD_NUM_OF_PADDLES 2

#include <stdbool.h>
#include "Paddle.h"
#include "Ball.h"
#include "Table.h"
#include "Net.h"

typedef struct Board {
    int width;
    int height;
    Table table;
    Net net;
    Paddle paddles[BOARD_NUM_OF_PADDLES];
    Ball ball;
} Board;

Board board_new(int width, int height);
void board_move_paddle(Board* board, int direction);
void board_move_ball(Board* board, int currentTime, int* lastTime, int* smer);
int board_check_round_win(Board* board);
void board_reset(Board* board, int winner);

#endif
