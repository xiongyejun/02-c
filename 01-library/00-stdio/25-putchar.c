// putchar
// int putchar(int character)
// write character to stdout

#include <stdio.h>

int main(void)
{
	char c;
	for(c = 'A'; c <= 'Z'; c++)
		putchar(c);

	return 0;
}
