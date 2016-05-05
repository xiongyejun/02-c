// fgets
// char * fgets(char * str, int num. FILE * stream);

#include <stdio.h>

int main(void)
{
	FILE * pf;
	char my_string[100];

	pf = fopen("mylog.txt", "r");
	if(pf == NULL) perror("Error opening file");
	else{
		while(fgets(my_string, 100, pf) != NULL)
			printf("%s", my_string);

		fclose(pf);
	}
	return 0;
}
