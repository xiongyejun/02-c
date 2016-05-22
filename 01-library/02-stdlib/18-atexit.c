// int atexit(void (*fuc)(void))
// set function to be executed on exit
// A zero value is returned if the function was successfully registered
// if it failed, a non-zero value is returned.
//
#include <stdio.h>
#include <stdlib.h>

void fnExit1(void)
{
	puts("Exit function 1.");
}

void fnExit2(void)
{
	puts("Exit function 2.");
}

int main(void)
{
	atexit(fnExit1);
	atexit(fnExit2);
	puts("Main function.");
	abort();
	return 0;
}
