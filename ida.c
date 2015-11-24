/* Iterative Deeping A* Implementation 
 * W is the weight factor used for WIDA*
 * It can be defined at compile time,
 * otherwise it is set to 1 (no weight factor)
 */

#include "action.h"
#include "heuristic.h"
#include "ida.h"
#include "node.h"

#ifndef W
#define W 1
#endif

struct node ida(struct node *N, int *b, int *b_, 
		unsigned long int *gen, unsigned long int *ex)
{
	int a = pstates(N->s) - N->p;
	int i, hval;
	struct node N_;
	(*ex)++;

	while (a > 0) {
		if (a >= L) {
			tswap(L, N->s);
			a -= L;
			N_.p = R;
			(*gen)++;
		} else if (a >= D) {
			tswap(D, N->s);
			a -= D;
			N_.p = U;
			(*gen)++;
		} else if (a >= R) {
			tswap(R, N->s);
			a -= R;
			N_.p = L;
			(*gen)++;
		} else if (a >= U) {
			tswap(U, N->s);
			a -= U;
			N_.p = D;
			(*gen)++;
		}

		hval = h(N->s);
		N_.g = N->g + 1;
		N_.f = N_.g + (W * hval);
		
		if (N_.f > *b) {
			if (N_.f < *b_) *b_ = N_.f;
		} else {
			for (i = 0; i < 16; i++) {
				N_.s[i] = N->s[i];
			}

			if (!hval) {
				N_.n = 0;
				return N_;
			}
			
			struct node Ret;
			Ret = ida(&N_, b, b_, gen, ex);
			
			if (!Ret.n)
				return Ret;
		}
		tswap(N_.p, N->s);
	}
	N_.n = 1;
	return N_;
}
