// double atof(const char * str)
// Convert string to double
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	double n, m;
	double pi = 3.1415926535;
	char buffer[256];

	printf("enter degrees:");
	fgets(buffer, 256, stdin);
	n = atof(buffer);
	m = sin(n*pi/180);
	printf("the sine of %f degrees is %f\n", n, m);
	
	return 0;
}
