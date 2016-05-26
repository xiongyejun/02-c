#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int c;

	c = 0;

	system("stty raw");
	while('q' != c)
	{
		c = getchar();
		printf("press: %c\n", c);
	}
	system("stty cooked");
	
	return 0;
}
