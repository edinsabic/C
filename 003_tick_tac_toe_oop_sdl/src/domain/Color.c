#include "color.h"

Color color_new(int r, int g, int b) {
	Color this = {
		.r = r,
		.g = g,
		.b = b,
	};
	return this;
}

Color color_red() { return color_new(255, 0, 0); }
Color color_blue() { return color_new(0, 0, 255); }
Color color_black() { return color_new(0, 0, 0); }