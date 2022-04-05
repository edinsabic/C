#include "Paddle.h"

Paddle paddle_new(int x, int y, int height, int width) {
	Paddle this = {
		.x = x,
		.y = y,
		.height = height,
		.width = width,
	};

	return this;
}