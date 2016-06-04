// 打印所有输入行 P30

#include <stdio.h>
#define MAX_LINE	256

void reverse_line(char str[], int len)
{
	char tmp;
	int i;

	for(i = 0; i < len / 2; i++)
	{
		tmp = str[i];
		str[i] = str[len-1-i];
		str[len - 1 - i] = tmp;
	}
}
int get_line(char str[], int len)
{
	int c, i;

	for(i = 0; i < len - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		str[i] = c;

	str[i] = '\0';

	return i;
}

int main(void)
{
	int len;
	char str[MAX_LINE];

	while((len = get_line(str, MAX_LINE)) > 0)
	{
		reverse_line(str, len);
		printf("after reverse: %s\n", str);
	}

	return 0;
}
