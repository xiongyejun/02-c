// long double strtold(const char * str, char ** endptr);
// convert string to long double
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char szorbits[] = "90613.305   365.24";
	char * pEnd;
	long double f1, f2;

	f1 = strtold(szorbits, &pEnd);
	f2 = strtold(pEnd, NULL);

	printf("f1 = %Lf, f2 = %Lf\n", f1, f2);
	printf("pluto takes %.2Lf years to complete an orbit.\n", f1/f2);

	return 0;
}
