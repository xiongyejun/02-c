// void free(void * ptr);
// deallocate memory block
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int * buffer1, * buffer2, * buffer3;

	buffer1 = (int *) malloc(100 * sizeof(int));
	buffer2 = (int *) calloc(100, sizeof(int));
	buffer3 = (int *) realloc(buffer2, 500*sizeof(int));
	free(buffer1);
	free(buffer3);

	return 0;
}
