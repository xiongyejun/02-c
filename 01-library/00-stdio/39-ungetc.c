// int ungetc(int character, FILE * stream)
// unget character from stream
//
#include <stdio.h>

int main(void)
{
	FILE * pf;
	int c;
	char buffer[256];

	pf = fopen("mylog.txt", "rt");
	if(NULL == pf) perror("error opening file");
	else 
		while(!feof(pf))
		{
			c = getc(pf);
			if(EOF == c) break;
			if('#' == c) ungetc('@', pf);
			else 
				ungetc(c, pf);
			
			if(fgets(buffer, 256, pf) != NULL)
				fputs(buffer, stdout);
			else
				break;
		}

	return 0;
}
