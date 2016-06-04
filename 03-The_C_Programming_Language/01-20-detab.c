// P25,练习1-20
// 用适当的空格(为了能看见，这里用-表示)替换制表符
#include <stdio.h>

#define N_TAB		8	 // 制表符终止位

int main(void)
{
	int c;
	int c_count;	// 某行输入的总字符数
	int i;
	int n_space;

	n_space = c_count = i = c = 0;
	while((c = getchar()) != EOF)
	{
		if('\t' == c)
		{
			n_space = N_TAB - (c_count % N_TAB);
			for(i = 0; i < n_space; i++, c_count++)
				putchar('-');
		}
		else if('\n' == c)
		{
			c_count = 0;
			putchar(c);
		}
		else
		{
			c_count++;
			putchar(c);
		}
	}

	return 0;
}
