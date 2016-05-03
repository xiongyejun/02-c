// fprintf
// int fprintf(FILE * stream, const char * format, ...);
// 用法与printf差不多，将字符写到 stream中去

#include <stdio.h>

int main(void)
{
	FILE * pf;
	int n;
	char name[100];

	pf = fopen("myfile.txt", "w");
	for(n = 0; n < 3; n++)
	{
		puts("please, enter a name:");
		gets(name);
		fprintf(pf, "Name %d [%-10.10s]\n", n+1, name);
	}
	fclose(pf);

	return 0;
}
