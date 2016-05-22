// long long int strtoll (const char * str, char ** endptr, int base)
// convert string to long long integer
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char szNumbers[] = "18564923  17b00a12b   -01100011010110000010001101100 0x6fffff";
	char * pEnd;
	long long int lli1, lli2, lli3, lli4;

	lli1 = strtoll(szNumbers, &pEnd, 10);
	lli2 = strtoll(pEnd, &pEnd, 16);
	lli3 = strtoll(pEnd, &pEnd, 2);
	lli4 = strtoll(pEnd, NULL, 0);

	printf("the decimal equivalents are: %lld, %lld, %lld and %lld.\n", lli1,lli2,lli3,lli4);

	return 0;
}
