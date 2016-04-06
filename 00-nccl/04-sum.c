#include <stdio.h>

int main(void)
{
	printf("\nsum 1 to 100\n");
;
	int sum = 0;
	for (int i = 0; i <= 100; i++)// i+=2)// i++,i++)
	{
		if (i % 2) continue;
		sum += i;
	}

	printf("sum = %d\n", sum);
	return 0;
}
