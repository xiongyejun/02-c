// int strncmp(const char * str1, const char * str2, size_t num)
// compare characters of two strings
//
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[3][5] = {"R202", "C3PO", "R2A6"};
	int n;

	puts("looking for R2 astromech droids...");
	for(n = 0; n < 3; n++)
		if(strncmp(str[n], "R2xx", 2) == 0)
			printf("found %s\n", str[n]);

	return 0;
}
