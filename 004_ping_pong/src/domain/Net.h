
#ifndef _DOMAIN_NET

#define _DOMAIN_NET

typedef struct Net {
	int x;
	int y;
	int width;
	int height;
} Net;

Net net_new(int x, int y, int width, int height);

#endif