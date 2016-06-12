// 将证书n转换为以b为底的数
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char * s)
{
	int i, j;
	int c;

	for(i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itob_ans(int n, char * s, int b)
{
	static char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i, sign;

	if(b < 2 || b > 36)
	{
		fprintf(stderr, "EX3_5: Cannot support base %d\n", b);
		exit(EXIT_FAILURE);
	}

	if((sign = n) < 0)
		n = -n;

	i = 0;
	do
	{
		s[i++] = digits[n % b];
	} while ((n /= b) > 0);

	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void itob(int n, char * s, int b)
{
	int sign, i;
	sign = n;

	if(b > 16)
	{
		printf("b = %d > 16, error\n", b);
		return;
	}
	
	do
	{
		s[i] = abs(n % b) + '0';
		if(s[i] > '9')
			s[i] = s[i] + 'a' - '9' - 1;
		i++;
	} while(n /= b);

	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);

		
}

int main(void)
{
	int n;
	char s[256];

	printf("input a num:");
	scanf("%d", &n);
	itob(n, s, 16);
	printf("n = %d, s = %s\n", n, s);

	itob_ans(n, s, 16);
	printf("ans:n = %d, s = %s\n", n, s);
	return 0;
}
