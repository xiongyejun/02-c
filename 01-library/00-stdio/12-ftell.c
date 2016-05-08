// ftell
// long int ftell(FILE * stream)

#include <stdio.h>

int main(void)
{
	FILE * pf;
	long size;

	pf = fopen("mylog.txt", "rb");
	if(NULL == pf) perror("Error opening file");
	else
	{
		fseek(pf, 0, SEEK_END);
		size = ftell(pf);
		printf("size of mylog.txt: %ld bytes.\n", size);
		
		rewind(pf);
		size = ftell(pf);
		printf("after rewind size = %ld\n", size);
		fclose(pf);
	}

	return 0;
}
