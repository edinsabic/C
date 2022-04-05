#ifndef _DOMAIN_BALL

#define _DOMAIN_BALL

#include "Color.h"

typedef struct Ball {
	int x;
	int y;
	int width;
	int height;
} Ball;

Ball ball_new(int x, int y, int width, int height);

#endif 