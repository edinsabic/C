#include "Ball.h"

Ball ball_new(int x, int y, int height, int width) {
	Ball this = {
		.x = x,
		.y = y,
		.height = height,
		.width = width,
	};

	return this;
}	