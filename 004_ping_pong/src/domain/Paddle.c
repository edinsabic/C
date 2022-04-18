#include "Paddle.h"

Paddle paddle_new(int x, int y, int width, int height, int curXpos, int curYtop, int curYbot) {
	Paddle this = {
		.x = x,
		.y = y,
		.width = width,
		.height = height,
		.curXpos = curXpos,
		.curYtop = curYtop,
		.curYbot = curYbot,
	};

	return this;
}