// size_t strlen(const char * str)
// get string length
//
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str_input[256];
	printf("enter a sentence:");
	gets(str_input);
	printf("the sentence entered is %u characters long.\n", (unsigned)strlen(str_input));
	
	return 0;
}
