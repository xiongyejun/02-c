// 打印所有输入行 P30

#include <stdio.h>
#define MAX_LINE	256

int get_line(char str[], int len)
{
	int c, i;

	for(i = 0; i < len - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		str[i] = c;

	if('\n' == c) str[i++] = c;
	str[i] = '\0';

	return i;
}

int main(void)
{
	int len;
	char str[MAX_LINE];

	while((len = get_line(str, MAX_LINE)) > 0)
		printf("%s\n", str);

	return 0;
}
