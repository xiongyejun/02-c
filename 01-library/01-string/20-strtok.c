// char * strtok(char * str, const char * delimiters)
// split string into tokens
//
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "test - This, a sample string.";
	char * pch;

	printf("splitting string \"%s\" into tokens:\n", str);
	pch = strtok(str, " ,.-");
	while(NULL != pch)
	{
		printf("%s\n", pch);
		pch = strtok(NULL, " ,.-");
	}

	return 0;
}
