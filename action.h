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

#ifndef ACTION
#define ACTION

#define U 1
#define R 2
#define D 4
#define L 8


/* Finds and returns the blank tile in a given state */

int fz(int *s);


/* Returns the applicable actions for a given state
 * Using octal numbers as described above
 */

int pstates(int *s);


/* Applies given action to given state in place */

int tswap(int a, int *s);
#endif
