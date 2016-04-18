// ./a.out < 20-delcomment.c 2>/dev/null

#include <stdio.h>

/* abcd */
// abcd
int get_input_type(char c)
{
	if (c == '/')
		return 1;

	if (c == '*')
		return 2;

	if (c == '\n')
		return 3;

	if (c == '\'')
		return 4;

	if (c == '\\')
		return 5;

	return 0;
}

#define debug(fmt, args...) fprintf(stderr, fmt, ##args)
int main(void)
{
	int state = 0;

	while (1)
	{
		char c;
		int input;

		c = getchar();
		input = get_input_type(c);

		if (c == EOF)
			break;

		debug("%c", c);
		
		if (0 == state && 1 == input) // "/
		{
			state = 1;
		}
		else	
		if (0 == state && 4 == input) // '/'
		{
			state = 5;
			putchar(c);
		}
		else	
		if (1 == state && 1 == input) // "//
		{
			state = 4;
		}	
		else	
		if (1 == state && 2 == input) // "/*
		{
			state = 2;
		}	
		else	
		if (2 == state && 0 == input) // "/* abc
		{
			state = 2;
		}	
		else	
		if (2 == state && 2 == input) // "/* abc *
		{
			state = 3;
		}	
		else	
		if (3 == state && 1 == input) // "/* abc */
		{
			state = 0;
		}
		else	
		if (3 == state && 0 == input) // "/* abc * abc
		{
			state = 2;
		}
		else	
		if (4 == state && 3 == input) // "//  abc \n
		{
			state = 0;
			putchar(c);
		}	
		else
		if (5 == state && 4 == input) // '/'
		{
			state = 0;
			putchar(c);
		}
		else
		if (5 == state && 5 == input) // '\'
		{
			state = 6;
			putchar(c);
		}
		else
		if (6 == state && 4 == input) // '\'
		{
			state = 5;
			putchar(c);
		}
		else
		if (6 == state && 5 == input) // '\\'
		{
			state = 5;
			putchar(c);
		}
		else
		if (6 == state && 0 == input) // '\'
		{
			state = 5;
			putchar(c);
		}
		else	
		if (state == 0 || 5 == state)
			putchar(c);
		

		debug("input = %d, state = %d\n", input, state);	
	}
	return 0;
}
