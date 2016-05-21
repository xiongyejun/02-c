// float strtof(const char * str, char ** endptr);
// convert string to float
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char szorbits[] = "686.97      365.24";
	char * pEnd;
	float f1, f2;

	f1 = strtof(szorbits, &pEnd);
	f2 = strtof(pEnd, NULL);

	printf("f1 = %f, f2 = %f\n", f1, f2);
	printf("one martian year takes %.2f earth years.\n", f1/f2);

	return 0;
}

