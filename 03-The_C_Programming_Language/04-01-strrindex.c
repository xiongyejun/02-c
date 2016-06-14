// 返回字符串t在s中最右边的位置
// 不包含则返回-1

#include <stdio.h>
#include <string.h>

#define MAX_LEN		128

int strrindex(char s[], char t[])
{
	int i, j, k;

	for(i = strlen(s) - strlen(t); i >= 0; i--)
	{
		for(j = i, k = 0; t[k] == s[j] && t[k] != '\0'; j++, k++)
			;

		if(k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}

int main(void)
{
	char s[MAX_LEN];	
	char t[MAX_LEN];	

	printf("input a str:");
	scanf("%s", s);
	printf("input a substr:");
	scanf("%s", t);

	printf("s = %s\n", s);
	printf("t = %s\n", t);
	printf("strrindex = %d\n", strrindex(s, t));

	return 0;
}
