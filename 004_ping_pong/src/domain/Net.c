#include "Net.h"

Net net_new(int x, int y, int width, int height) {
	Net this = {
		.x = x,
		.y = y,
		.width = width,
		.height = height,
	};

	return this;
}