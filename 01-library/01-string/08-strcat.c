// char * strcat(char * des, const char * src)
// concatenate strings
//des and src shall not overlap
//
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[80];

	strcpy(str, "these ");
	strcat(str, "strings ");
	strcat(str, "are ");
	strcat(str, "concatenated.");

	puts(str);
	
	return 0;
}
