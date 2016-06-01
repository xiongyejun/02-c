// 打印制表符\t、回退符\b、反斜杠\\ .. 
#include <stdio.h>

int main(void)
{
	int c;

	while((c = getchar()) !=EOF)
		if('\t' == c)
			printf("\\t");
		else
		if('\b' == c)		// ctrl+h  输入回退符
			printf("\\b");
		else
		if('\\' == c)
			printf("\\\\");
		else
			putchar(c);

	return 0;
}
