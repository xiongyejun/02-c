#include <stdio.h>
#include "04-4.5-calc.h"

#define MAXVAL		100
int sp = 0;
double val[MAXVAL];

void print_val()
{
	if(sp > 0)
		printf("val[%d] == %8g\n", sp-1, val[sp-1]);
	else
		printf("error: sp == 0\n");
}

void clear_val()
{
	sp = 0;
}

void push(double f)
{
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}
