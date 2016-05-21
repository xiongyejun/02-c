// double strtod(const char * str, char ** endptr)
// convert string to double
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char szorbits[] = "365.24       29.53";
	char * pEnd;
	double d1, d2;

	d1 = strtod(szorbits, &pEnd);
	printf("szorbits = %s, pEnd = %s\n", szorbits, pEnd);
	d2 = strtod(pEnd, NULL);
	printf("d1 = %f, d2 = %f\n", d1, d2);
	printf("the moon completes %.2f orbits per Earth year.\n", d1/d2);

	return 0;
}
