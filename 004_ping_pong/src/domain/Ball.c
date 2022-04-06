#include "Ball.h"

Ball ball_new(int x, int y, int width, int height) {
	Ball this = {
		.x = x,
		.y = y,
		.width = width,
		.height = height,
	};

	return this;
}	