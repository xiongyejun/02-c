// void _Exit(int status)
// terminate calling process
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE * pf;
	pf = fopen("mylog.txt1", "r");
	if(NULL == pf)
	{
		printf("error opening file [mylog.txt1]\n");
		_Exit(EXIT_FAILURE);
	}
	else
	{
		printf("open");
		fclose(pf);
	}

	return 0;
}
