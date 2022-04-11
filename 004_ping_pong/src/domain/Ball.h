
#ifndef _DOMAIN_BALL

#define _DOMAIN_BALL

#include "Color.h"

typedef struct Ball {
	int x;
	int y;
	int width;
	int height;
	float xVelocity;
	float yVelocity;
} Ball;

Ball ball_new(int x, int y, int width, int height);

#endif 