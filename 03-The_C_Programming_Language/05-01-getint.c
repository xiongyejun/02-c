//
#include <stdio.h>
#include <ctype.h>
#include "04-4.5-calc.h"

int getint(int *pn)
{
	int c, sign;

	while(isspace(c = getch()))
		;
	if(!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c);
		return 0;
	}
	sign = c;
	if(c == '+' || c == '-')
		c = getch();
	if(!isdigit(c))
	{
		ungetch(c);
		return 0;
	}
	for(*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');

	sign = (sign == '-') ? -1 : 1;
	*pn *= sign;
	if(c != EOF)
		ungetch(c);
	return c;
}

int main(void)
{
	int n, arr[10] = {99,99,99,99,99,99,99,99,99,99};

	for(n = 0; n < 10 & getint(&arr[n]) != EOF; n++)
		printf("arr[%d] = %d\n", n, arr[n]);


	return 0;
}
