// int scanf(const char * format, ...)
// read formatted data from stdin
//
#include <stdio.h>

int main(void)
{	
	char str[100];
	int i;

	printf("enter your family name:");
	scanf("%79s", str);
	printf("enter your age:");
	scanf("%d", &i);
	printf("Mr. %s, %d years old.\n", str, i);
	printf("enter a hexadecimal number:");
	scanf("%x", &i);
	printf("you have enterd %#x (%d).\n", i, i);

	return 0;
}
