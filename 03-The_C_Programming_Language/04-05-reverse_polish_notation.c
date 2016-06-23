// 逆波兰表达式

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP		100	// 操作数或运算符的最大长度
#define NUMBER		'0'	// 标识找到一个数
#define BUFSIZE		100
#define MAXVAL		100	// 栈val的最大深度

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


char buf[BUFSIZE];		// 用于ungetch函数的缓冲区
int bufp = 0;			// buf中下一个空闲位置

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

int getop(char s[])
{
	int i, c;

	while((s[0] = c = getch()) == ' ' || c == '\t')
		;

	s[1] = '\0';

	i = 0;
	if(isalpha(c))
	{
		while(isalpha(s[++i] = c = getch()))
			;
		s[i] = '\0';

		if(c != EOF) ungetch(c);
		if(strcmp(s, "sin") == 0)
			return 's';
		else
		if(strcmp(s, "exp") == 0)
			return 'e';
		else
		if(strcmp(s, "cos") == 0)
			return 'c';
		else
		if(strcmp(s, "pow") == 0)
			return 'p';
	}

	if(!isdigit(c) && c != '.' && c != '-')
		return c;

	i = 0;
	if(c == '-')
	{
	 	if(!isdigit(c = getch()))
		{
			ungetch(c);
			return '-';
		}
		else
			s[++i] = c;
	}

	if(isdigit(c))
		while(isdigit(s[++i] = c = getch()))
			;
	if(c == '.')	// 收集小数部分
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	
	if(c != EOF)
		ungetch(c);
	
	return NUMBER;
}

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
