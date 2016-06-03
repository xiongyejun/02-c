// P25,练习1-21
// 用最少的制表符和空格替换一串空格
#include <stdio.h>

#define N_TAB		8	 // 制表符终止位
#define IN			1	 // 碰到了空格
#define OUT			0	 // 碰到了非空格
int main(void)
{
	int c;
	int c_count;		 // 某行输入的总字符数
	int i;
	int n_space;		 // 一串空格的个数
	int p_space, p_tab;	 // 需要的最少的空格和制表符
	int state;
	int n_tmp;

	state = OUT;
	n_tmp = n_space = c_count = i = c = 0;
	p_space = p_tab = 0;
	while((c = getchar()) != EOF)
	{
		if(' ' == c && state == OUT)
		{
			state = IN;
			n_space++;
		}
		else if(' ' == c && state == IN)
			n_space++;
		else if(' ' != c && state == OUT)
		{
			putchar(c);
			if('\t' == c)	// 输入制表符的时候，总字符数比起到制表符终止处
				c_count = (c_count / N_TAB + 1) * N_TAB;
			else
				c_count++;
		}
		else if(' ' != c && state == IN)
		{
			state = OUT;
			// 打印最少的空格和制表符
			if((c_count / N_TAB) == ((c_count+n_space) / N_TAB))
			{
				p_tab = 0;
				p_space = n_space;
			}
			else
			{
				n_tmp = N_TAB - c_count % N_TAB;	// 补齐c_count到制表符终止符
				p_tab = 1 + (n_space - n_tmp) / N_TAB;	// 剩下的space再按N_TAB计算
				p_space = (n_space - n_tmp) % N_TAB;
			}
			for(i = 0; i < p_tab; i++)
				putchar('\t');
			for(i = 0; i < p_space; i++)
				putchar(' ');

			c_count+=n_space;
			n_space = 0;
			putchar(c);
			if('\t' == c)	// 输入制表符的时候，总字符数比起到制表符终止处
				c_count = (c_count / N_TAB + 1) * N_TAB;
			else
				c_count++;
		}
		
		if('\n' == c)
			c_count = 0;


	}

	return 0;
}
