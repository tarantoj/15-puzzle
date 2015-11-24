/* Node Structure
 * s stores the state
 * f stores the evaluation function value
 * g stores the cost of the path up to s
 * n is null solution flag, 1 for no solution,
 * 0 for solution found
 * p stores the previous action applied
 */

#ifndef NODE
#define NODE

struct node {
	int *s;
	int f, g, n, p;
};

#endif
