// FILE * temfile(void);
// open a temporary file
//
#include <stdio.h>
#include <string.h>

int main(void)
{
	char buffer[256];
	FILE * pf;
	pf = tmpfile();

	do
	{
		if(!fgets(buffer, 256, stdin)) break;
		fputs(buffer, pf);
	} while(strlen(buffer) > 1);

	rewind(pf);

	while(!feof(pf))
	{
		if(fgets(buffer, 256, pf) == NULL) break;
		fputs(buffer, stdout);
	}
	fclose(pf);
	

	return 0;
}
