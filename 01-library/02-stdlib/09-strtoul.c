// unsigned long int strtoul(const char * str, char ** endptr, int base)
// convert string to unsigned long integer
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char buffer[256];
	unsigned long ul;

	printf("enter an unsigned number:");
	fgets(buffer, 256, stdin);
	ul = strtoul(buffer, NULL, 0);
	printf("value entered: %lu. Its double: %lu\n", ul, ul*2);

	return 0;
}
