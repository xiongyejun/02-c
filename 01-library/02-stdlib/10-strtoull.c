// unsigned long long int strtoull (const char * str, char ** endptr, int base)
// convert string to unsigned long long integer
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char szNumbers[] = "18564923  17b00a12b   -01100011010110000010001101100 0x6fffff";
	char * pEnd;
	unsigned long long int ulli1, ulli2, ulli3, ulli4;

	ulli1 = strtoull(szNumbers, &pEnd, 10);
	ulli2 = strtoull(pEnd, &pEnd, 16);
	ulli3 = strtoull(pEnd, &pEnd, 2);
	ulli4 = strtoull(pEnd, NULL, 0);

	printf("the decimal equivalents are: %llu, %llu, %llu and %llu.\n", ulli1,ulli2,ulli3,ulli4);

	return 0;
}
