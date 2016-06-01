// 统计空格、制表符、换行符的个数
#include <stdio.h>

int main(void)
{
	int c;
	int n_space;
	int n_tab;
	int n_newline;

	n_space = 0;
	n_tab = 0;
	n_newline = 0;

	while((c = getchar()) !=EOF)
		if(' ' == c)
			n_space++;
		else
		if('\t' == c)
			n_tab++;
		else
		if('\n' == c)
			n_newline++;
		
	printf("space = %d\n", n_space);
	printf("tab = %d\n", n_tab);
	printf("newline = %d\n", n_newline);

	return 0;
}
