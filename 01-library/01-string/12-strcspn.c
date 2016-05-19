// size_t strcspn(const char * str1, const char * str2)
// get span until character in string
//
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "fcba73";
	char keys[] = "1c234567890";
	int i;

	i = strcspn(str, keys);
	printf("the first number in str is at position %d.\n", i+1);

	return 0;
}
