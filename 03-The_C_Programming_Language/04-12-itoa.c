// 用递归实现 
#include <stdio.h>
#include <stdlib.h>

int i = 0;
void itoa(int n, char s[])
{
	if(n / 10) itoa(n / 10, s);
	s[i++] = abs(n % 10) + '0';
}

int main(void)
{	
	int n;
	char s[256];

	printf("input a number:");
	scanf("%d", &n);

	if(n < 0)
		s[i++] = '-';

	itoa(abs(n), s);
	s[i] = '\0';

	printf("n = %d, s = %s\n", n, s);
}
