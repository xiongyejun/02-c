// feof
// int feof(FILE * stream)
#include <stdio.h>

int main(void)
{
	FILE * pf;
	int n = 0;

	pf = fopen("mylog.txt", "rb");
	if(NULL == pf) perror("error opening file");
	else
	{
		while(fgetc(pf) != EOF) n++;
		if(feof(pf))
		{
			puts("end of file reached.");
			printf("total number of bytes read: %d\n", n);
		}
		else
			puts("end of file was not reached.");
		fclose(pf);
	}
	return 0;
}
