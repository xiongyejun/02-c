// 将x循环右移n位
#include <stdio.h>

unsigned rightrot_ans(unsigned x, unsigned n)
{
	while(n > 0)
	{
		if((x & 1) == 1)
			x = (x >> 1) | ~(~0U >> 1);
		else
			x = (x >> 1);
		n--;
	}
	return x;
}

unsigned int rightrot(unsigned x, unsigned int n)
{
	int i;
	int int_len;

	int_len = sizeof(int) * 8;

	// 如果最后是1，x>>1后，&1000 0000 0000 0000
	//			 0，x>>1
	for(i = 0; i < n; i++)
		if(x & 1u)
			x = (x>>1) | (1<<(int_len-1));
		else
			x>>=1;
	return x;	

}

int main(void)
{
	unsigned x;
	unsigned int n;

	for(x = 0; x < 700; x+=49)
		for(n = 1; n < 8; n++)
			printf("%u, %d: %u\n", x, n, rightrot_ans(x, n));
/*
	x = 0xff; // 0000 0000 1111 1111 
	n = 4;

	printf("x = %u, rightrot %d = 0x%x\n", x, n, rightrot(x, n));
	printf("x = %u, rightrot_ans %d = 0x%x\n", x, n, rightrot_ans(x, n));
*/
	return 0;
}
