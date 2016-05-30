// int isgraph(int c)
// check if character has graphical representation
//
#include <stdio.h>
#include <ctype.h>

int main(void)
{	
	FILE *pf;
	int c;
	pf = fopen("myfile.txt", "r");
	if(pf)
	{
		do 
		{
			c = fgetc(pf);
			if(isgraph(c)) putchar(c);
		} while (c != EOF);
		fclose(pf);
	}

	return 0;
}
