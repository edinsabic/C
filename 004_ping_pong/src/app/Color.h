#ifndef _APP_COLOR
#define _APP_COLOR

typedef struct Color {
    int r;
    int g;
    int b;
} Color;

static Color COLOR_RED = { .r = 255, .g = 0, .b = 0 };
static Color COLOR_BLUE = { .r = 0, .g = 0, .b = 255 };
static Color COLOR_BLACK = { .r = 0, .g = 0, .b = 0 };
static Color COLOR_WHITE = { .r = 255, .g = 255, .b = 255 };

#endif