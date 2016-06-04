#include <stdio.h>

int main(void)
{
	int c;
	
	// ctrl+d 输入的是EOF
	c = (getchar() != EOF);
	printf("c = %d\n", c);

	printf("EOF = %d\n", EOF);

	return 0;
}
