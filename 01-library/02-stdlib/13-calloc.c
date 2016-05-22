// void * calloc(size_t num, size_t size)
// allocate and zero-initialize array
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, n;
	int * p;

	printf("Amount of numbers to be entered:");
	scanf("%d", &i);
	p = (int *) calloc(i, sizeof(int));

	if(NULL == p) exit(1);
	for(n = 0; n < i; n++)
	{
		printf("enter number #%d:", n+1);
		scanf("%d", &p[n]);
	}
	printf("you have enterd:");
	for(n = 0; n < i; n++)
		printf("%d ", p[n]);
	
	putc('\n', stdout);
	free(p);


	return 0;
}
