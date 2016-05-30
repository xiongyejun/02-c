// int toupper(int c)
// convert lowercase letter to uppercase
//
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int i = 0;
	char str[] = "Test 123 !`/., String.\n";
	char c;

	while(str[i])
	{
		c = str[i++];
		putchar(toupper(c));
	}

	return 0;
}
