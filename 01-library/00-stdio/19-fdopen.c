// fdopen
// FILE * fdopen(int fildes, const char * mode);
#include <stdio.h>

int main(void)
{
	FILE * pf = fdopen(0, "w+");
	fprintf(pf, "%s\n", "hello!");
	fclose(pf);

	return 0;
}
