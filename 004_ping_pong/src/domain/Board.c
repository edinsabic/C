#include "Board.h"
#include <stdio.h>

// Board ti pove kok kvadratkov mas

Board board_new(int width, int height) {
    Board this = {
        .width = width,
        .height = height,
    };

    int a = width / 2;
    int b = height / 2;

    int xZ = width / 20; // sirina zoge
    int bZ = height / 20;// tankost zoge

    this.table = table_new(4, height / 8, width - 10, (height - 5) - (height / 4));

    this.net = net_new(a, height / 8, 1, width - (width/4) - 5, bZ);

    int x = width / 15;
    int y = height / 2;

    int xP = width / 100;// tankost paddla
    int yP = height / 5; // sirina paddla

    this.paddles[0] = paddle_new(x, y - (yP / 2), xP, yP);
    this.paddles[1] = paddle_new(width - x, height - y - (yP / 2), xP , yP);

    this.ball = ball_new(x + 10, b - (bZ / 2), xZ, bZ);
    
    return this;
}

void board_move_paddle(Board* board, int direction) {
    // '/' določi kateri paddle se bo premaknil (L/R), '%' pa kam, gor/dol (-/+)
    if (direction < 4) {
        board->paddles[direction / 2].y += (((direction % 2 == 0) ? -1 : 1) * 10);
    }
}

void board_move_ball(Board* board, int currentTime, int* lastTime, int* smer) {
    // vsakih 10 ms se premakne en frame desno

    if (currentTime > *lastTime + 10) {
        if (board->ball.x > (board->paddles[1].x - (board->width)/100 - 4 - 20)) {
            // printf("Zadel smo desni paddle, zamenji vrednost tm kamor je shranjen smer na -1\n");
            *smer = -1;
        } else if (board->ball.x < board->paddles[0].x + board->paddles[0].width) {
            *smer = 1;
        }

        board->ball.x = board->ball.x + (*smer * 3);
        *lastTime = currentTime;
    }
}