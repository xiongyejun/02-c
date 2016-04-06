#include <stdio.h>

int main(void)
{
	int num = 0;

	printf("\ndemo judge number parity\n");

	while (2)
	{	
		printf("input a number:");	
		scanf("%d", &num);

		if (num % 2){
			printf("num %d is odd\n", num);
		} else {
			printf("num %d is even\n", num);
		}
	}
	return 0;
}
