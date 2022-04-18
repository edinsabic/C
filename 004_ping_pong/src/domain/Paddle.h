
#ifndef _DOMAIN_PADDLE

#define _DOMAIN_PADDLE

typedef struct Paddle {
	int x;
	int y;
	int height;
	int width;
	int curXpos;
	int curYtop;
	int curYbot;
} Paddle;

Paddle paddle_new(int x, int y, int width, int height, int curXpos, int curYtop, int curYbot);

#endif