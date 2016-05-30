// int ispunct(int c)
// check if character is a punctuation character
// The standard "c" locale considers punctuation characters
// all graphic characters(as in isgraph) that are not
// alphanumeric(as in isalnum)

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int i = 0;
	int cx = 0;
	char str[] = "Hello, welcome!";

	while(str[i])
	{
		if(ispunct(str[i])) cx++;
		i++;
	}	
	printf("Sentence contains %d punctuation characters.\n", cx);

	return 0;
}

