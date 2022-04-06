#include "Table.h"

Table table_new(int x, int y, int width, int height) {
	Table this = {
		.x = x,
		.y = y,
		.width = width,
		.height = height,
	};

	return this;
}