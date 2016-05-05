// fputc
// int fputc(int character, FILE * stream);

#include <stdio.h>

int main(void)
{
	FILE * pf;
	char c;

	pf = fopen("mylog.txt", "a");

	if(pf != NULL)
	{
		for(c = 'A'; c <= 'Z'; c++)
			fputc(c, pf);
		
		fputc('\n', pf);
		fclose(pf);
	}
	return 0;
}
