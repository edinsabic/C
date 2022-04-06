#include "Board.h"

// Board ti pove kok kvadratkov mas

Board board_new(int width, int height) {
    Board this = {
        .width = width,
        .height = height,
    };

    this.table = table_new(4, height / 8, width - 10, (height - 5) - (height / 4));

    int x = width / 15;
    int y = height / 2;

    int xP = width / 100;// tankost paddla
    int yP = height / 5; // sirina paddla

    this.paddles[0] = paddle_new(x, y - (yP / 2), xP, yP);
    this.paddles[1] = paddle_new(width - x, height - y - (yP / 2), xP , yP);

    int a = width / 2;
    int b = height / 2;

    int xZ = width / 20; // sirina zoge
    int bZ = height / 20;// tankost zoge

    this.ball = ball_new(a - (xZ/2), b - (bZ/2), xZ, bZ);
    
    return this;
}