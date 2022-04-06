
#ifndef _DOMAIN_BOARD
#define _DOMAIN_BOARD

#define BOARD_NUM_OF_PADDLES 2

#include <stdbool.h>
#include "Paddle.h"
#include "Ball.h"
#include "Table.h"

typedef struct Board {
    int width;
    int height;
    Table table;
    Paddle paddles[BOARD_NUM_OF_PADDLES];
    Ball ball;
} Board;

Board board_new(int width, int height);

#endif
