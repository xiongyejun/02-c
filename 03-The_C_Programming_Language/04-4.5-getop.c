#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "04-4.5-calc.h"

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
