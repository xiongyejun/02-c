// 如果字符串t出现再字符串s的尾部，返回1，否则0
#include <stdio.h>

int strend(char *s, char *t)
{
	int i;
	int j;

	while(s[i] != '\0')
		i++;
	while(t[j] != '\0')
		j++;

	if(i < j) return 0;

	while(j >= 0 && (s[i--] == t[j--]))
		;

	if (j == -1) return 1;

	return 0;
}

int main(void)
{
	char s[80];
	char t[80];

	printf("input str s: ");
	scanf("%s", s);
	printf("input str t: ");
	scanf("%s", t);

	if(1 == strend(s, t))
		printf("t appears at end of s\n");
	else
		printf("t not appears at end of s\n");
		

	return 0;
}
