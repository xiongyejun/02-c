// char * strncpy(char * des, const char * src, size_t num)
// copy characters from string
// des and src shall not overlap(memmove safer)
// No null-character is implicitly appended at the end of destination if source is longer than num.
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[] = "to be or not to be";
	char str2[40];
	char str3[40];

	strncpy(str2, str1, sizeof(str2));

	memset(str3, 'a', sizeof(str3)-1);
	str3[sizeof(str3)-1] = '\0';

	puts(str3);
	strncpy(str3, str2, 5);
//	str3[5] = '\0';

	puts(str1);
	puts(str2);
	puts(str3);



	return 0;
}
