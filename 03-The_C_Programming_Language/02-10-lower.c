// 大写字母转小写
//
#include <stdio.h>

int main(void)
{
	int c;

	c = '0';
	while((c=getchar()) != EOF)
		putchar((c >= 'A' && c <= 'Z') ? (c+'a'-'A') : c);

	return 0;
}
