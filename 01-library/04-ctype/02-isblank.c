// int isblank(int c);
// check if character is blank
// checks whether c is a blank character
//
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char c;
	int i = 0;
	char str[] = "Example sentence to test isblank\n";

	while(str[i])
	{
		c = str[i++];
		if (isblank(c)) c = '\n';
		putchar(c);
	}

	return 0;
}
