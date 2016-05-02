// clearerr
// void clearerr(FILE * stream);
//
#include <stdio.h>


int main(void)
{
	FILE *pf;
	pf = fopen("myfile.txt", "r");
	if (NULL == pf) perror ("Error opening file___:");
	else {
		fputc('x', pf);
		if(ferror(pf)) {
			printf("error writing to myfile.txt\n");
			clearerr(pf);
		}
		fgetc(pf);
		if(!ferror(pf))
			printf("no errors reading myfile.txt\n");

		fclose(pf);
	}	
	return 0;
}
