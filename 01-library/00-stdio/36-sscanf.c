// int sscanf(const char * s, const char * format, ...)
// read formatted data from string
//
#include <stdio.h>

int main(void)
{
	char sentence[] = "rudolph test is 12 years old";
	char str[20];
	int i;

	sscanf(sentence, "%s %*s %*s %d", str, &i);
	printf("%s -> %d\n", str, i);

	return 0;
}
