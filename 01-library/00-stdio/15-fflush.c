// fflush
// int fflush(FILE * stream)
// 没成功，不知道为何
//
#include <stdio.h>

int main(void)
{
/*
 	FILE * pf;
	char buffer[80];

	pf = fopen("mylog.txt", "r+");
	if(NULL == pf) perror("error opening file");
	else
	{
		fputs("test", pf);
//		fgets(buffer, 80, pf);
//		printf("before fflush buffer = %s\n", buffer);
//		fflush(pf);
		fgets(buffer, 80, pf);
		printf("after fflush buffer = %s\n", buffer);
		fclose(pf);
	}
*/
	int a;
	char c;
	
	scanf("%d", &a);
	fflush(stdin);
	c = getchar();

	printf("a = %d, c = %c\n", a, c);

	return 0;
}
