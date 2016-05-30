// int tolower(int c)
// convert uppercase letter to lowercase
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
		putchar(tolower(c));
	}

	return 0;
}
