// void srand(unsigned int seed)
// initialize random number generator
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	printf("First number: %d\n", rand() % 100);
	srand(time(NULL));
	printf("Random number: %d\n", rand() % 100);
	srand(1);
	printf("Again the first number: %d\n", rand() % 100);

	return 0;
}
