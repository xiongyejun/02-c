// const char * strchr(const char * str, int character)
//		 char * strchr(		 char * str, int character)
//	locate first occurrence of character in string
//
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "this is a sample string";
	char * pch;

	printf("looking for the 's' character in \"%s\"...\n", str);
	pch = strchr(str, 's');
	while(NULL != pch){
		printf("found at %ld\n", pch-str+1);
		pch = strchr(pch+1, 's');
	}

	printf("\\0 = %ld\n", strchr(str, '\0')-str+1);
	printf("strlen(str) = %lu\n", strlen(str));

	return 0;
}
