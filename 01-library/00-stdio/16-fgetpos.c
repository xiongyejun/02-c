// fgetpos
// int fgetpos(FILE * stream, fpos_t * pos)

#include <stdio.h>

int main(void)
{
	FILE * pf;
	int c, n;
	fpos_t pos;

	pf = fopen("mylog.txt", "r");
	if(NULL == pf) perror("error opening file");
	else
	{
		c = fgetc(pf);
		printf("1st character is %c\n", c);
		fgetpos(pf, &pos);
		for(n = 0; n < 3; n++)
		{
			fsetpos(pf, &pos);
			c = fgetc(pf);
			printf("2st character is %c\n", c);
		}
		fclose(pf);
	}

	return 0;
}
