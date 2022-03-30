#ifndef _DOMAIN_COLOR 
#define _DOMAIN_COLOR

typedef struct Color {
	int r;
	int g;
	int b;
} Color;

Color color_new(int r, int g, int b);
Color color_red();
Color color_blue();
Color color_black();

#endif