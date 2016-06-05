// x中从第p(从0开始计算)位开始的n个（二进制）位设置为
// y中的最右边n(从0开始计算)位的值
#include <stdio.h>
#include <limits.h>

int setbits(int x, int p, int n, int y)
{
	int int_len;
	int tmp;

	tmp = int_len = 0;
	int_len = sizeof(int) * 8;
	if(0 == p && n >= int_len - 1) return y;
	y = y & ~(~0 << (n+1));				// 将y变为最右边n位的值
	y = y<<(int_len-n-p-1);				// 与要替换的位置对应起来

	tmp = x;
	tmp = tmp & (~0 << (int_len-p));				// 取出x的前p位
	y = y | tmp;

	if(p+n+1 >= int_len)
		return y;
	else
	{
		x = x & ~(~0 << (int_len-p-n-1));						// 取出x的后p+n位
		y = y | x;
	}
	return y;
}

int main(void)
{
	int x, y, p, n;
		
	x = 31;	// 0000 0000 0000 0000 0000 0000 0001 1111
	y = 5;	// 0000 0000 0000 1111 0000 0000 0000 0101
	p = 28;
	n = 2;

	printf("%d\n", setbits(x, p, n, y));

	return 0;
}
