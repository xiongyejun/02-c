// const char * strrchr(const char * str, int character)
//		 char * strrchr(	  char * str, int character)
//	locate last occurrence of character in string
//
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "this is a sample string";
	char * pch;
	pch = strrchr(str, 's');
	printf("last occurence of 's' found at %ld \n", pch-str+1);

	return 0;
}
