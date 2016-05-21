// int atoi(const char * str)
// convert string to integer
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	char buffer[256];
	printf("enter a number:");
	fgets(buffer, 256, stdin);
	i = atoi(buffer);
	printf("the value entered is %d. Its double is %d.\n", i, i * 2);

	return 0;
}
