// int isalnum(int c)
// check if character is alphanumeric
//
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int i;
	char str[] = "c3po...";
	i = 0;
	int i_return;

	i_return = isalnum(str[i]);
	while(i_return) 
	{
		printf("%d i_return = %d, %c\n", i, i_return, str[i++]);
		i_return = isalnum(str[i]);
	}

	printf("The first %d characters are alphanumeric.\n", i);

	return 0;
	
	return 0;
}
