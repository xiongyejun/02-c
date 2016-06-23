#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "04-4.5-calc.h"
#define MAXOP	100

int main(void)
{
	int type;
	double op2;
	char s[MAXOP];

	while((type = getop(s)) != EOF)
	{
		switch(type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0)
					push(pop() - op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				//push((double)((int)pop() % (int)op2));
				push(fmod(pop(), op2));
				break;
			case 's':
				push(sin(pop()));
				break;
			case 'e':
				push(exp(pop()));
				break;
			case 'c':
				push(cos(pop()));
				break;
			case 'p':
				op2 = pop();
				push(pow(pop(), op2));
				break;
			case '\n':
				printf("result: %.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}
