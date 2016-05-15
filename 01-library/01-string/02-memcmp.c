// int memcmp(const void * ptr1, const void * ptr2, size_t num)
// compare two blocks of memory
//
#include <stdio.h>
#include <string.h>

int main(void)
{
	char buffer1[] = "DWgaotP12df0";
	char buffer2[] = "DWGAOTP12DF0";
	int n;
	
	n = memcmp(buffer1, buffer2, sizeof(buffer1));
	if(n > 0) printf("'%s' is greater than '%s'\n", buffer1, buffer2);
	else if(n < 0) printf("'%s' is less than '%s'\n", buffer1, buffer2);
	else printf("same");

	return 0;
}
