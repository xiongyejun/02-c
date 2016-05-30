// int iscntrl(int c)
// check if character is a control character
//
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int i = 0;
	char str[] = "first line \n second line \n";

	while(!iscntrl(str[i]))
		putchar(str[i++]);


	return 0;
}
