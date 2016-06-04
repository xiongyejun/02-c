// 打印单词长度的直方图

#include <stdio.h>

#define IN				1
#define OUT				0

int main(void)
{
	int c, len, state;
	int arr_word_len[20] = {0};
	int i, j, k;

	len = i = 0;
	state = OUT;

	while((c = getchar()) != EOF)
		if('\n' == c || '\t' == c || ' ' == c)
		{
			if(state == IN)
			{
				arr_word_len[i++] = len;
				state = OUT;
				len = 0;
			}
		}
		else if(state == OUT)
		{
			state = IN;
			len = 1;
		}
		else if(state == IN)
			len++;
		
		printf("histogram:\n");
		for(j = 0; j < i; j++)
		{
			for(k = 0; k < arr_word_len[j]; k++)
				printf("*");
			
			putchar('\n');
		}

	return 0;
}
