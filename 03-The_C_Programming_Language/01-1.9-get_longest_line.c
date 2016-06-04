// 读取输入行，并打印最长的行P29

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

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while((to[i] = from[i]) != '\0') i++;
}

int main(void)
{
	int len;
	int max;
	char str[MAX_LINE];
	char longest[MAX_LINE];

	max = 0;
	while((len = get_line(str, MAX_LINE)) > 0)
		if(len > max)
		{
			max = len;
			copy(longest, str);
		}

	if(max > 0)
		printf("longest: %s\n", longest);

	return 0;
}
