#ifndef _DOMAIN_PADDLE

#define _DOMAIN_PADDLE

typedef struct Paddle {
	int x;
	int y;
	int height;
	int width;
} Paddle;

Paddle paddle_new(int x, int y, int height, int width);

#endif