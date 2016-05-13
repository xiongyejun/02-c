// putc
// int putc(int character, FILE * stream)

#include <stdio.h>

int main(void)
{
	FILE * pf;
	char c;

	pf = fopen("mylog.txt", "wt");
	for (c = 'A'; c <= 'z'; c++)
	{
		putc(c, pf);
		printf("c = %c\n", c);
	}
	putc('\n', pf);
	fclose(pf);

	return 0;
}
