#include "Board.h"

// Board ti pove kok kvadratkov mas

Board board_new(int width, int height) {
    Board this = {
        .width = width,
        .height = height,
    };

    int x = width / 15;
    int y = height / 2;

    int sirinaPaddla = height / 5;
    int visinaPaddla = width / 100;

    this.paddles[0] = paddle_new(x, y, sirinaPaddla, visinaPaddla);
    this.paddles[1] = paddle_new(x, y, sirinaPaddla, visinaPaddla);

    this.ball = ball_new(width / 2, height / 2, width / 20, height / 20);
    
    return this;
}