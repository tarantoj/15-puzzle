#ifndef IDA
#define IDA
#include "node.h"

extern int b, b_;
extern long int gen, ex;

struct node ida(struct node *N, int *b, int *b_,
		unsigned long int *gen, unsigned long int *ex);
#endif
