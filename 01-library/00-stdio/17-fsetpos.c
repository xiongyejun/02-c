// fsetpos
// int fsetpos(FILE * stream, const fpos_t * pos)
//
#include <stdio.h>

int main(void)
{
	FILE * pf;
	fpos_t pos;

	pf = fopen("mylog.txt", "w");
	fgetpos(pf, &pos);
	fputs("that is a sample\n", pf);
	fsetpos(pf, &pos);
	fputs("this", pf);
	fclose(pf);

	return 0;
}
