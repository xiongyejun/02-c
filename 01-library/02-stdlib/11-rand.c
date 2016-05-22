// int rand(void);
// generate random number
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int iSecret, iGuess;

	srand(time(NULL));
	iSecret = rand() % 10 + 1;

	do
	{
		printf("Guess the number(1 to 10):");
		scanf("%d", &iGuess);
		if(iSecret < iGuess) puts("the secret number is lower:");
		else if(iSecret > iGuess) puts("the secret number is higher");
	} while (iSecret != iGuess);

	puts("congratulations!");


	return 0;
}
