
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
void itoa(int n, char s[])
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

	s[i] = '\0';
	reverse(s);

}

int main(void)
{	
	int n;
	int int_len;
	char s[256];

	int_len = sizeof(int) * 8;
	n = (int)pow(2, int_len - 1);

	printf("n = %u\n", n);
	
	itoa(n, s);
	printf("n = %u, s = %s\n", n, s);
	
	itoa(-n, s);
	printf("-n = %u, s = %s\n", -n, s);
}
