#ifndef HEURISTIC
#define HEURISTIC

int xdist(int x);
int ydist(int y);

/* Calculates the manhattan distance between two points */

int mdist(int a, int b);


/* Calculates and returns the heuristic value for the given state */

int h(int *s);
#endif
