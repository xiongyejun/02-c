// getc
// int getc(FILE * stream)

#include <stdio.h>

int main(void)
{
	FILE * pf;
	int c;
	
	pf = fopen("mylog.txt", "r");
	if(NULL == pf) perror("Error opening file");
	else
	{
		while((c = getc(pf)) != EOF)
		{
			printf("%c", c);
		}
		fclose(pf);
	}
	return 0;
}
