#include <stdio.h>
#include "my_getch.h"

int main(void)
{
	char c;

	while('q' != (c = my_getch()))
			printf("you press %c\n", c);

	return 0;
}
