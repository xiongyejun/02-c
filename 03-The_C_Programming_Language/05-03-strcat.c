// 用指针处理
#include <stdio.h>
void my_strcat_ans(char * s, char * t)
{
	while('\0' != *s)
		++s;

	while('\0' != (*s++ = *t++))
		;
}

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
	char s1[100] = "abcd";
	char * t1 = "efg";

	printf("s = %s, t = %s\n", s, t);
	my_strcat(s, t);
	printf("strcat s = %s\n", s);

	printf("s1 = %s, t1 = %s\n", s1, t1);
	my_strcat_ans(s1, t1);
	printf("strcat s1 = %s\n", s1);

	return 0;
}
