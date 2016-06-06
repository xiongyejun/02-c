// 将x中从第p（从右边数，0开始）位开始的n（从1数）个（二进制）位求反
#include <stdio.h>

// 原理是：对要求反位置的数，进行同位置为1、其他位置为0的异或？
unsigned invert_ans(unsigned x, int p, int n)
{
	return x ^ (~(~0U << n) << p);
}

// 又理解错了，是从右边第p为开始，再数n个数求反
// 错了错了错了错了
unsigned invert(unsigned x, int p, int n)
{
	unsigned tmp;
	// 1、先不需要的变为0：000……需要的……000
	// 1.1 左边不需要的变为0：~0>>再<<可以不考虑int的长度，再取反：000011111111111
	// 1.2 x右边变为0
	// 1.3 &获取
	// 再取反: (1111需要的取反了11111)
	tmp = ~(~((~0>>(p+1))<<(p+1)) & ((x>>(p+1-n))<<(p+1-n)));
	// 2、将x要替换的部分变为111111，其他不变
	// 2.1 获取这样一个数，需要部分为1，其他为0: 00001111100000
	// 2.2 取反，变成了左边不需要动的为0，其他为1
	// 2.3 右边不需要动的变为0
	// 2.4  与x或 
	x = x | (((~((~0>>(p+1))<<(p+1)))>>(p+1-n))<<(p+1-n));

	return tmp & x;
}

int main(void)
{
	unsigned num;
	int p, n;

	num = 0xff;  // 0000 0000 1111 1111
	p = 4;
	n = 4;

	printf("num = %u, invert num = %u\n", num, invert(num, p, n));
	printf("num = %u, invert_ans num = %u\n", num, invert_ans(num, p, n));
	return 0;
}
