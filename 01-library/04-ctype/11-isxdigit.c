// int isxdigit(int c)
// check is character is hexadecimal digit
// checks whether c is a hexdecimal digit character
// hexadecimal digits are any of: 0 1 2 3 4 5 6 7 8 9 a b c d e f
//
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
	char str[] = "fff";
	long int number;

	if(isxdigit(str[0]))
	{
		number = strtol(str, NULL, 16);
		printf("The hexadecimal number %lx is %ld.\n", number, number);
	}


	return 0;
}
