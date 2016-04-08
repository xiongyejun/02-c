#include <stdio.h>

int main(void)
{
	/*
	 * 1 | 1 = 1	1 & 1 = 1
	 * 1 | 0 = 0	1 & 0 = 0
	 * 0 | 0 = 0	0 & 0 = 0
	 */
	int num = 0;
	int ret = 0;
	int sum = 0;
	int i = 0;
	printf("input a number\n");
	scanf("%d", &num);

	// 0x64 = 0110 0100
	// 0x63 = 0110 0011
	// &    = 0110 0000 -> 0x60
	// 1 << n == 2^n
	// 0x4 = 0100
	// 0x3 = 0011
	// &   = 0000
	// n & (n - 1) -> clear most-right bit 1
	
	while (num != 0)
	{
		num = num & (num - 1);
		printf("num = 0x%x\n", num);
		sum++;
	}

#if 0	
	for (i = 0; i < 32; i++)
	{
		if (num & (1 << i))
		{
			printf("bit %d is 1\n", i);
			sum++;
		}
	}
#endif
	printf("num %d(0x%x) has %d bit 1\n", num, num, sum);
#if 0
	ret = num & 1;
	printf("ret = %d\n", ret);
	
	ret = num & 2;
	printf("ret = %d\n", ret);
	
	ret = num & 4;
	printf("ret = %d\n", ret);
#endif
	return 0;
}
