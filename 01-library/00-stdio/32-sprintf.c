// int sprintf(char * str, const chat * format, ...)
// write formatted data to string
// on success, the total number of characters written is returned
// on failure, a negative number is returned

#include <stdio.h>

int main(void)
{
	char buffer[50];
	int n, a = 5, b = 3;
	n = sprintf(buffer, "%d plus %d is %d", a, b, a + b);
	printf("[%s] is a string %d chars long\n", buffer, n);

	return 0;
}
