#include <stdio.h>

void print_bin(int num)
{
	int len = sizeof(num) * 8;
	int i;

	printf("num = %d, num bin = ", num);
	
	if (0 == num)
	{
		printf("0\n");
		return;
	}

	for (i = len - 1; i >= 0; i--)	// 略去高位0
	{
		if (num & (1 << i)) break;
	}	

	
	for (; i >= 0; i--)
		printf("%d", (num & (1 << i)) != 0);

	printf("\n");

}

int main(void)
{
	int num = 0;
	printf("input a number");
	scanf("%d", &num);
	print_bin(num);
	return 0;
}
