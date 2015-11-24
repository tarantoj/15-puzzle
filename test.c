#include <stdio.h>

#define U 1
#define L 2
#define D 4
#define R 8

int pstates(int s)
{
	        int a = s;
		        int b = U+L+D+R;

			        int x = a % 4;
				        int y = a / 4;

					        if (x == 0) b -= R;
						        if (x == 3) b -= L;
							        
							        if (y == 0) b -= U;
								        if (y == 3) b -= D;

									        return b;
}


int main(void)
{
	int i;

	for (i = 0; i < 16; i++) printf("%d ", pstates(i));
	printf("\n");
	for (i = 0; i < 16; i++) printf("%d ", i);

	return 0;
}
