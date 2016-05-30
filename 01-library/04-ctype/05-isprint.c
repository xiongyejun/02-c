// int isprint(int c)
// check if character is printable
//
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int i = 0;
	char str[] = "first line \n second line \n";

	while(isprint(str[i]))
		putchar(str[i++]);


	return 0;
}
