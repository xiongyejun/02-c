// fseek
// int fseek(FILE * stream, long int offset, int origin)

#include <stdio.h>

int main(void)
{
	FILE * pf;
	pf = fopen("mylog.txt", "wb");
	fputs("this is an apple.\n", pf);
	fseek(pf, 9, SEEK_SET);
	fputs(" sam", pf);
	fclose(pf);

	return 0;
}
