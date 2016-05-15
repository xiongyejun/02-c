// void * memmove(void * des, const void * src, size_t num)
// move block of memory
//
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "memmove can be very useful......";
	memmove(str + 20, str + 15, 11);
	puts(str);
	
	return 0;
}
