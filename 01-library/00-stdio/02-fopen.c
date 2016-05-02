// fopen
// FILE * fopen(const char * filename, const char * mode);

#include <stdio.h>

int main(void)
{
	FILE * pf;
	pf = fopen("myfile.txt", "w");
	if(pf != NULL)
	{
		fputs("fopen example", pf);
		fclose(pf);
	}
	return 0;
}
