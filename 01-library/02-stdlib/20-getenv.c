// char * getenv(const char * name)
// get environment string
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char * p;
	p = getenv("PATH");
	if(NULL != p)
		printf("the current path is: %s\n", p);

	p = getenv("USER");
	if(NULL != p)
		printf("USER = %s\n", p);

	p = getenv("TMP_DIR");
	if(NULL != p)
		printf("TMP_DIR = %s\n", p);
	else
		printf("No TMP_DIR\n");
	return 0;
}
