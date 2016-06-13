// 输出的字符控制最短长度width
// 用x代替空格方便看
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

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
void itoa(int n, char s[], int width)
{
	int i;
	int sign;

	sign = n;

	i = 0;
	do
	{
		s[i++] = abs(n % 10) + '0';
	} while(n /= 10);

	if(sign < 0)
		s[i++] = '-';

	for(; i < width; i++)
		s[i] = 'x';

	s[i] = '\0';
	reverse(s);

}

int main(void)
{	
	int n;
	int width;
	char s[256];

	printf("input a number:");
	scanf("%d", &n);
	printf("input a number for width:");
	scanf("%d", &width);
	itoa(n, s, width);
	printf("n = %u, width = %d, s = %s\n", n, width, s);
}
