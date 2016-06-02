// 每行一个单词的打印输入
#include <stdio.h>

#define IN			1
#define OUT			0

int main(void)
{
	int c, state;
	
	state = OUT;
	while((c = getchar()) != EOF)
	{	
		if('\n' == c)
			;
		else
		if(' ' == c || '\t' == c)
		{
			state = OUT;
		//	putchar('\n');
		}
		else
		if(state == OUT)
		{
			putchar('\n');
			state = IN;
			putchar(c);
		}
		else
			putchar(c);

	}

	return 0;
}
