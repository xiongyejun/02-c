// int setvbuf(FILE * stream, char * buffer, int node, size_t size)
// change stream buffering
//
#include <stdio.h>

int main(void)
{
	FILE * pf;

	pf = fopen("mylog.txt", "w");
	setvbuf(pf, NULL, _IOFBF, 1024);

	fputs("setvbuf", pf);

	fclose(pf);

	return 0;
}
