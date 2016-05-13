// perror
// void perror(const char * str);
// print error message

#include <stdio.h>

int main(void)
{
	FILE * pf;
	pf = fopen("mylog.txt", "rb");
	if(NULL == pf)
		perror("the following error occcured");
	else
		fclose(pf);

	return 0;
}	
