// size_t strxfrm(char * des, const char * src, size_t num)
// transform string using locale
//
#include <stdio.h>
#include <string.h>

int main(void)
{
	char * src = "1234567890 abc";
	char des[100];
	size_t len = strxfrm(des, src, 50);

	printf("src = %s, des = %s, len = %zu\n", src, des, len);

	return 0;
}
