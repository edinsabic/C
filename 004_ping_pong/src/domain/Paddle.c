#include "Paddle.h"

Paddle paddle_new(int x, int y, int width, int height) {
	Paddle this = {
		.x = x,
		.y = y,
		.width = width,
		.height = height,
	};

	return this;
}