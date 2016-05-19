// const char * strpbrk(const char * str1, const char * str2)
//		 char * strpbrk(	  char * str1, const char * str2)
//	locate characters in string
//
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "this is a sample string";
	char key[] = "aeiou";
	char * pch;

	printf("vowels in '%s':", str);
	pch = strpbrk(str, key);
	while(pch != NULL)
	{
		printf("%c ", *pch);
		pch = strpbrk(pch + 1, key);
	}
	printf("\n");

	return 0;
}
