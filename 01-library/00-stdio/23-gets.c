// gets
// char * gets(char * str);
// get string from stdin
//
#include <stdio.h>

int main(void)
{
	char str[256];
	printf("Insert your full address:");
	gets(str);
	printf("Your address is : %s\n", str);
	return 0;
}
