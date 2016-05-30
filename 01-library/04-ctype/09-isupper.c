// int isupper(int c)
// check if character is uppercase letter
//
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int i = 0;
	char str[] = "Test String.\n";
	char c;

	while (str[i])
	{
		c = str[i++];
		if(isupper(c)) c = tolower(c);
		putchar(c);
	}


	return 0;
}
