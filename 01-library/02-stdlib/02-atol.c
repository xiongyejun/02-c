// long int atol(const char * str)
// convert string to long integer
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	long int li;
	char buffer[256];

	printf("enter a long number:");
	fgets(buffer, 256, stdin);
	li = atol(buffer);
	printf("the value entered is %ld, Its double is %ld.\n", li, 2*li);

	return 0;
}
