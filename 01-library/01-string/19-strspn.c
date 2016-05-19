// size_t strspn(const char * str1, const char * str2)
// get span of character set in string
//
#include <stdio.h>
#include <string.h>

int main(void)
{
	int i;
	char str1[] = "129th";
	char str2[] = "1234567890";

	i = strspn(str1, str2);
	printf("the initial number has %d digits.\n", i);

	return 0;
}
