// int isalpha(int c);
// check if character is alphabetic
//
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int i = 0;
	char str[] = "c++";

	while(str[i])
	{
		if(isalpha(str[i])) 
			printf("character %c is alphabetic\n", str[i++]);
		else
			printf("character %c is not alphabetic\n", str[i++]);
	}

	return 0;
}
