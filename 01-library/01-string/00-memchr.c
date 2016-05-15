// const void * memchr(const void * ptr, int value, size_t num)
//		 void * memchr(		 void * ptr, int value, size_t num)
//	locate character in block of memory
//	ptr: pointer to the block of memory whrer the serch is performed
//	value: value to be located.the value is passed as an int, but the function performs a byte per byte search using the unsigned char conversion of this value
//	num: number of bytes to be analyzed.
//	return value: a pointer to first occurrence of value in the block of memory pointed by ptr

#include <stdio.h>
#include <string.h>

int main(void)
{
	char * pch;
	char str[] = "example string";
	pch = (char *) memchr(str, 'p', strlen(str));
	if(NULL == pch)
		printf("'p' not found.\n");
	else
		printf("'p' found at position %ld.\n", pch-str+1);

	return 0;
}
