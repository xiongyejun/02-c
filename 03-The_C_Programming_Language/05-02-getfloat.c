//
#include <stdio.h>
#include <ctype.h>
#include "04-4.5-calc.h"

int getfloat(double *pf)
{
	int c, sign, power;

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
	for(*pf = 0.0; isdigit(c); c = getch())
		*pf = 10.0 * *pf + (c - '0');

	if(c == '.')
	{
		c = getch();
		power = 1;
		for(;isdigit(c); c = getch())
		{
			*pf = 10.0 * *pf + (c - '0');
			power *= 10;
		}
		*pf = *pf / (double)power;
	}

	sign = (sign == '-') ? -1 : 1;
	*pf *= sign;
	if(c != EOF)
		ungetch(c);
	return c;
}

int main(void)
{
	int n;
	double arr[10] = {99.9,99.9,99.9,99.9,99.9,99.9,99.9,99.9,99.9,99.9};

	for(n = 0; n < 10 & getfloat(&arr[n]) != EOF; n++)
		printf("arr[%d] = %f\n", n, arr[n]);


	return 0;
}
