/* Number correlated to swap direction
 * inspired by unix file permissions
 *
 * 1 = up
 * 2 = right
 * 4 = down
 * 8 = left
 *
 * Examples
 * 3 = 1+2 = up+right
 * 15 = 1+2+4+8 = up+right+down+left
 *
 * Visual aid
 * 00 01 02 03
 * 04 05 06 07
 * 08 09 10 11
 * 12 13 14 15
 *
 */

#include "action.h"


/* Finds and returns the blank tile in a given state */

int fz(int *s)
{
	int i = 0;

	while(s[i] != 0) i++;

	return i;
}


/* Returns the applicable actions for a given state
 * Using octal numbers as described above
 */

/*
int pstates(int *s)
{
	int a = fz(s);
	int b = U+L+D+R;

	x = a % 4;
	y = a / 4;

	if (x == 0) b -= R;
	if (x == 3) b -= L;
	
	if (y == 0) b -= U;
	if (y == 3) b -= D;

	return b;
}

*/
int pstates(int *s)
{
	switch (fz(s)) {
		case 0:
			return (R + D);
		case 1:
			return (R + D + L);
		case 2:
			return (R + D + L);
		case 3:
			return (D + L);
		case 4:
			return (U + R + D);
		case 5:
			return (U + R + D + L);
		case 6:
			return (U + R + D + L);
		case 7:
			return (U + D + L);
		case 8:
			return (U + R + D);
		case 9:
			return (U + R + D + L);
		case 10:
			return (U + R + D + L);
		case 11:
			return (U + D + L);
		case 12:
			return (U + R);
		case 13:
			return (U + R + L);
		case 14:
			return (U + R + L);
		case 15:
			return (U + L);
		default:
			return 0;
	}
}


/* Applies given action to given state and returns a new state */

int tswap(int a, int *s)
{
	int z = fz(s);

	switch(a) {
		case U:
			s[z] = s[z - 4];
			s[z - 4] = 0;
			break;
		case R:
			s[z] = s[z + 1];
			s[z + 1] = 0;
			break;
		case D:
			s[z] = s[z + 4];
			s[z + 4] = 0;
			break;
		case L:
			s[z] = s[z - 1];
			s[z - 1] = 0;
			break;
	}

	return 0;
}
