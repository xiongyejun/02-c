// void setbuf(FILE * stream, char * buffer)
// set stream buffer
//
#include <stdio.h>

int main(void)
{
	char buffer[BUFSIZ];
	FILE * pf1, *pf2;

	pf1 = fopen("myfile1.txt", "w");
	pf2 = fopen("myfile2.txt", "a");

	setbuf(pf1, buffer);
	fputs("this is sent to a buffered stream", pf1);
//	fflush(pf1);
	fputs("2222222222222222222222222", pf1);

	setbuf(pf2, NULL);
	fputs("this is sent to an unbuffered stream", pf2);

	fclose(pf1);
	fclose(pf2);
	
	printf("buffer = %s \n", buffer);

	return 0;
}
