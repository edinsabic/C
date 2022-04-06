
#ifndef _DOMAIN_TABLE

#define _DOMAIN_TABLE

typedef struct Table {
	int x;
	int y;
	int width;
	int height;
} Table;

Table table_new(int x, int y, int width, int height);

#endif