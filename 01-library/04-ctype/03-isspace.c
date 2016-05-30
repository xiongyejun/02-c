// int isspace(int c)
// check if character is a white-space
// for the "c" locale, white-space characters are any of:
// ' '	0x20	space(SPC)
// '\t'	0x09	horizontal tab(TAB)
// '\n'	0x0a	newline(LF)
// '\v' 0x0b	vertical tab(VT)
// '\f'	0x0c	feed(FF)
// '\r'	0x0d	carriage return(CR)
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char c;
	int i = 0;
	char str[] = "Example sentence to test isspace\n";

	while(str[i])
	{
		c = str[i++];
		if(isspace(c)) c = '\n';
		putchar(c);
	}

	printf("\\f \n\f");
	printf("\\r \n\r");


	return 0;
}
