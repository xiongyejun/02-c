// 用指针处理
#include <stdio.h>

void my_strcat(char * s, char * t)
{
	int i;
	int j;

	i = j = 0;
	while(s[i] != '\0')
		i++;

	while((s[i++] = t[j++]) != '\0')
		;
	
}

int main(void)
{
	char s[100] = "abcd";
	char * t = "efg";

	printf("s = %s, t = %s\n", s, t);
	my_strcat(s, t);
	printf("strcat s = %s\n", s);

	return 0;
}
