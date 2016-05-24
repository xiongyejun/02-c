// void exit(int status)
// terminate calling process
// Status code.
// If this is 0 or EXIT_SUCCESS, it indicates success
// If it is EXIT_FAILURE, it indicates failure.
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE * pf;
	char str[256];

	pf = fopen("mylog.txt", "r");

	if(NULL == pf)
	{
		printf("error opening file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("first line = %s\n", fgets(str, 256, pf));
		fclose(pf);
	}

	fputs("just test\n", stdout);

	return 0;
}
