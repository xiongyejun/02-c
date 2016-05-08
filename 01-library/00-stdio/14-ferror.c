// ferror
// int ferror(FILE * stream)
#include <stdio.h>

int main(void)
{
	FILE * pf;
	pf = fopen("mylog.txt", "r");
	if(NULL == pf) perror("error opening file");
	else
	{
		fputc('x', pf);
		if(ferror(pf))
			printf("error writing to mylog.txt\n");

		fclose(pf);
	}
	return 0;
}	
