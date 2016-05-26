// long int labs(long int n);
// absolute value
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	long int n, m;
	n = labs(65537L);
	m = labs(-100000L);

	printf("n = %ld\n", n);
	printf("m = %ld\n", m);

	return 0;
}

