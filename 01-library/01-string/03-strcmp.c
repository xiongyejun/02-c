// int strcmp(const char * str1, const char * str2)
// compare two strings
//
#include <stdio.h>
#include <string.h>

int main(void)
{
	char key[] = "apple";
	char buffer[80];

	do
	{
		printf("guess my favorite fruit? ");
		fflush(stdout);
		scanf("%79s", buffer);
	} while (strcmp(key, buffer) != 0);
	puts("correct answer!");

	return 0;
}
