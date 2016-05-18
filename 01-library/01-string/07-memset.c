// void * memset(void * ptr, int value, size_t num)
// fill block of memory
//
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "almost every programmer should know memset!";
	memset(str, '-', 6);
	puts(str);

	return 0;
}
