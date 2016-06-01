// clock_t clock(void);
// returns the processor time consumed by the progam
// typedef long clock_t
// define CLOCKS_PER_SEC((clock_t)1000)
//
#include <stdio.h>
#include <time.h>
#include <math.h>

#define MAX_NUM		1000000
int frequency_of_primes(int n)
{
	int i, j;
	int freq = n - 1;

	for(i = 2; i <= n; i++)
		for(j = sqrt(i); j > 1; j--)
			if(i % j == 0)
			{
				freq--;
				break;
			}

	return freq;
}

int main(void)
{
	clock_t t;
	int f;

	t = clock();
	printf("Calculating...\n");
	f = frequency_of_primes(MAX_NUM - 1);
	printf("The number of primes lower than %d is: %d\n", MAX_NUM, f);
	t = clock() - t;
	printf("CLOCKS_PER_SEC = %d.\n", CLOCKS_PER_SEC);
	printf("It took me %ld clicks(%f seconds).\n", t, ((float)t)/CLOCKS_PER_SEC);


	return 0;
}
