// int islower(int c)
// check if character is lowercase letter
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
		if(islower(c)) c = toupper(c);
		putchar(c);
	}


	return 0;
}
