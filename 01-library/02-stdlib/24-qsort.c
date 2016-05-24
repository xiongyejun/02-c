// void qsort(void * base, size_t num, size_t size, int(*compar)(const void * , const void*))
// sort elements of array
//
#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b)
{
	return (*(int *)a - *(int *)b);
}
int main(void)
{
	int n;
	int values[] = {40, 10, 100, 90, 10, 25};

	qsort(values, 6, sizeof(int), compare);
	for(n = 0; n < 6; n++)
		printf("%d ", values[n]);
	printf("\n");

	return 0;
}
