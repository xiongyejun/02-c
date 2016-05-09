// fscanf
// int fscanf(FILE * stream, const char * format, ...);
// read formatted data from stream

#include <stdio.h>

int main(void)
{
	char str[80];
	float f;
	FILE * pf;

	pf = fopen("mylog.txt", "w+");
	fprintf(pf, "%f %s", 3.1415, "PI");
	rewind(pf);
	fscanf(pf, "%f", &f);
	fscanf(pf, "%s", str);
	fclose(pf);
	printf("i have read: %f and %s\n", f, str);

	return 0;	
}
