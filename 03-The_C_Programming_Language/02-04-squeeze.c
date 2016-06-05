// 删除s1中与s2匹配字符
#include <stdio.h>

#define STR_LEN			128
void squeeze(char s1[], char s2[])
{
	int i, j;

	i = j = 0;

	while(s1[i] != '\0' && s2[i] != '\0')
	{
		if(s1[i] != s2[i])
			s1[j++] = s1[i];
		i++;
	}
	s1[j] = '\0';
}


int main(void)
{
	char s1[STR_LEN];
	char s2[STR_LEN];

	printf("input a        str: ");
	scanf("%s", s1);
	printf("input an other str: ");
	scanf("%s", s2);

	printf("s1     = %s\ns2     = %s\n", s1, s2);
	squeeze(s1, s2);
	printf("squeeze str = %s\n", s1);

	return 0;
}
