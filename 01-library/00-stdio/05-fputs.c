// fputs
// int fputs(const char * str, FILE * stream);

#include <stdio.h>

int main(void)
{
	FILE * pf;
	char sentence[256];

	printf("Enter sentence to append:");
	fgets(sentence, 256, stdin);
	pf = fopen("mylog.txt", "a");
	fputs(sentence, pf);
	fclose(pf);

	return 0;
}


