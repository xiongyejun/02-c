// freopen
// FILE * freopen(const char * filename, const char * mode, FILE * stream);
// reopen stream with different file or mode

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX		10
int main(void)
{
	char * str[10];
	int i;

/*	freopen("mylog.txt", "w", stdout);
	printf("this sentece is redirected to a file.\n");
	fclose(stdout);
*/
	freopen("mylog.txt", "r", stdin);
	for(i = 0; i < MAX; i++)
	{
		str[i] = (char *) malloc(100);
		scanf("%s", str[i]);
		printf("str[%d] = %s\n", i, str[i]);
		free(str[i]);
	}
	fclose(stdin);

	return 0;
}
