// const char * strstr(const char * str1, const char * str2)
//		 char * strstr(		 char * str1, const char * str2)
// locate substring
//
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "this is a simple string";
	char * pch;
	pch = strstr(str, "simple");
	printf("pch = %s\n", pch);

	strncpy(pch, "sample", 6);
	puts(str);

	return 0;
}
