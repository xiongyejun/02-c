// void abort(void)
// abort current process
// 
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE * pf;

	pf = fopen("notexist.txt", "r");
	if(NULL == pf)
	{
		fputs("error opening file\n", stderr);
		abort();
	}
	puts("just test");
	fclose(pf);

	return 0;
}
