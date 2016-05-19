// char * strncat(char * des, const char * src, size_t num)
// append characters from string
//
#include <stdio.h>
#include <string.h>

int main(void)
{	
	char str1[20];
	char str2[20];

	strcpy(str1, "to be ");
	strcpy(str2, "or not to be");
	strncat(str1, str2, 6);
	puts(str1);

	return 0;
}
