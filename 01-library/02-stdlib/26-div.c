// div_t div(int numer, int denom)
// integral division
// typedef struct {
//		int quot;
//		int rem;
//	} div_t;
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	div_t div_result;
	div_result = div(38, 5);
	printf("38 div 5 => %d, remainder %d.\n", div_result.quot, div_result.rem);

	return 0;
}
