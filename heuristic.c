#include <stdlib.h>
#include "heuristic.h"

int xdist(int x)
{
	return (x % 4);
}

int ydist(int y)
{
	return (y / 4);
}

/* Calculates the manhattan distance between two points */

int mdist(int a, int b)
{
	int x, y;

	x = abs(xdist(a) - xdist(b));
	y = abs(ydist(a) - ydist(b));

	return (x + y);
}


/* Calculates and returns the heuristic value for the given state */

int h(int *s)
{
	int i;
	int out = 0;
	
	for (i = 0; i < 16; i++) {
		if (s[i]) out += mdist(i, s[i]);
	}

	return out;
}
