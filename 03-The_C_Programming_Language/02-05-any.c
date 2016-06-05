// 在s1中查找s2中的任意字符
#include <stdio.h>

#define STR_LEN			128

int any(char s1[], char s2[])
{
	int i, j;

	i = j = 0;
	
	for(i = 0; s1[i] != '\0'; i++)
	{
		for(j = 0; s2[j] != 0; j++)
			if(s2[j] == s1[i])
				return i;
	}

	return -1;
}

int main(void)
{
	char s1[STR_LEN];
	char s2[STR_LEN];
	int pos;

	pos = 0;
	printf("input a        str: ");
	scanf("%s", s1);
	printf("input an other str: ");
	scanf("%s", s2);

	printf("s1     = %s\ns2     = %s\n", s1, s2);
	pos = any(s1, s2);
	if(-1 != pos) printf("pos = %d\n", pos);

	return 0;
}
