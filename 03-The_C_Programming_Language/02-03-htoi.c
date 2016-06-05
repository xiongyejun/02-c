// 十六进制转换为整型值
#include <stdio.h>

#define STR_LEN		20

int htoi(char s[])
{
	int i;
	int num;

	i = 2;
	num = 0;
	if('0' == s[0] && ('x' == s[1] || 'X' == s[1]))	
	{	while(s[i] != '\0')
		{
			if(s[i] >= '0' && s[i] <= '9')
				num = num * 16 + s[i] - '0';
			else
			if(s[i] >= 'a' && s[i] <= 'f')
				num = num * 16 + 10 + s[i] - 'a';
			else
			if(s[i] >= 'A' && s[i] <= 'F')
				num = num * 16 + 10 + s[i] - 'A';
			else
				return num;
			i++;
		}
		return num;
	}
	else
		return 0;
}

int main(void)
{
	char str[STR_LEN];
	while(1)
	{
		printf("input a str: ");
		scanf("%s", str);
		printf("%s = %d\n", str, htoi(str));
	}

	return 0;
}
