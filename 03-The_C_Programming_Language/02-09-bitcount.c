// 计算x的二进制形式中1的个数
#include <stdio.h>

int main(void)
{	
	int x;
	int count;

	count = 0;
	printf("intput a number: ");
	scanf("%d", &x);
	
	printf("x = %d", x);
	while(x != 0)
	{
		x&=(x-1);
		count++;
	}
	printf(", number 1 count = %d\n", count);

	return 0;
}
