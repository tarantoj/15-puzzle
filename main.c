/* James Taranto
 * October 2015
 *
 * Iterative Deepening A* Implementation
 *
 * Usage:
 * ./ida $inputfile
 *
 * Where inputfile is a file containing
 * a solvable 15-puzzle state represented by
 * sequential numbers separated by spaces
 * ie
 *
 * $ cat 1.puzzle
 * 14 13 15 7 11 12 9 5 6 0 2 1 4 8 10 3
 */


#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>
#include "ida.h"
#include "heuristic.h"
#include "node.h"

int main(int argc, char **argv)
{

	FILE *pfile;
	pfile = fopen(argv[1], "r");

	struct node N, Ret;
	int i;
	for (i = 0; i < 16; i++) {
		fscanf(pfile, "%d", &(N.s[i]));
	}

	int *b, *b_;
	unsigned long int *gen, *ex;
	b = malloc(sizeof(int));
	b_ = malloc(sizeof(int));
	gen = malloc(sizeof(unsigned long int));
	ex = malloc(sizeof(unsigned long int));
	*b = h(N.s);
	*gen = 0;
	*ex = 0;

	Ret.n = 1;
	N.g = 0;
	N.p = 0;

	printf("Initial State:");

	for (i = 0; i < 16; i++) {
		if (!(i % 4)) printf("\n");
		printf("%3.2d", N.s[i]);
	}

	printf("\nInitial Estimate = %d\n", *b);
	printf("Threshold =");

	clock_t tic, toc;
	double ttime;

	tic = clock();

	while(Ret.n) {
		*b_ = INT_MAX;
		Ret = ida(&N, b, b_, gen, ex);
		if (Ret.n) {
			*b = *b_;
			printf(" %d", *b);
		}
	}

	toc = clock();
	ttime = (double)(toc - tic)/CLOCKS_PER_SEC;

	printf("\nSolution = %d\n", *b);
	printf("Generated = %lu\n", *gen);
	printf("Expanded = %lu\n", *ex);
	printf("Time = %.2f\n", ttime);
	printf("Expanded/Second = %.0f\n", *ex/ttime);

	return 0;
}
