// long int strtol(const char * str, char ** endptr, int base)
// convert string to long interger

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char szNumbers[] = "2001 60c0c0 -110111010011010010000 0x6fffff";
	char * pEnd;
	long int li1, li2, li3, li4;

	li1 = strtol(szNumbers, &pEnd, 10);
	li2 = strtol(pEnd, &pEnd, 16);
	li3 = strtol(pEnd, &pEnd, 2);
	li4 = strtol(pEnd, NULL, 0);

	printf("the decimal equivalents are: %ld, %ld, %ld and %ld.\n", li1, li2, li3, li4);
	return 0;
}
