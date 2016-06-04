// 多个空格只输出一个
#include <stdio.h>

int main(void)
{
	int c1, c2;	// c2记录上一次的输入字符

	c1 = c2 = 0;
	while((c1 = getchar()) != EOF)
		if(c1 != ' ' || c2 != ' ')
		{
			putchar(c1);
			c2 = c1;
		}

	return 0;
}
