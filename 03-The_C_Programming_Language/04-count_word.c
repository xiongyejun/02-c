// 单词计数
#include <stdio.h>

#define IN			1
#define OUT			0

int main(void)
{
	int c, nl, nw, nc, state;
	
	state = OUT;
	nl = nw = nc = 0;
	while((c = getchar()) != EOF)
	{	
		nc++;
		if('\n' == c)
			nl++;

		if(' ' == c || '\n' == c || '\t' == c)
			state = OUT;
		else
		if(state == OUT)
		{
			state = IN;
			nw++;
		}
	}
	printf("nl = %d, nw = %d, nc = %d\n", nl, nw, nc);

	return 0;
}
