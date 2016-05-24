// int system(const char * command)
// execute system command
// return value:
// if command is a null pointer, the function returns a non-zero value in case a command procedsor is avaliable and a zero value if it is not
// if command is not a null pointer, the value returned depends on the system and library implenmentations , but it sis generally expected to be the status code returned by the called command
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;

	printf("Checking if processor is availabe...");
	if(system(NULL)) puts("ok");
	else exit(EXIT_FAILURE);
	
	i = system("dir");
	printf("dir: the value returned was: %d.\n", i);

	i = system("ls");
	printf("ls: the value returned was: %d.\n", i);
		

	return 0;
}
