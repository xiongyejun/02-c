// char * tmpnam(char * str)
// generate temporary filename
//
#include <stdio.h>

int main(void)
{
	char buffer[L_tmpnam];
	char * pointer;

	tmpnam(buffer);
	printf("tempname #1:%s\n", buffer);

	pointer = tmpnam(NULL);
	printf("tempname #2:%s\n", pointer);

	printf("l_tmpnam = %d\n", L_tmpnam);

	return 0;
}
