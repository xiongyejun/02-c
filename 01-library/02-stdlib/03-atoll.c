// long long int atoll(const char * str)
// convert string to long long integer
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	long long int lli;
	long int li;
	int i;

	char buffer[256];
	printf("enter a long long number:");
	fgets(buffer, 256, stdin);
	lli = atoll(buffer);

	printf("sizeof i = %lu, li = %lu, lli = %lu\n", sizeof(i), sizeof(li), sizeof(lli));
	printf("the value entered is %lld. Its double is %lld.\n", lli, 2*lli);
	
	return 0;
}
