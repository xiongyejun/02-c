// int snprintf(char * s, size_t n, const char * format, ...)
// write formatted output to sized buffer
//
#include <stdio.h>
#define LEN		30

int main(void)
{
	char buffer[LEN];
	int cx;

	cx = snprintf(buffer, LEN, "the half of %d is %d", 60, 60 / 2);

//	if(cx >= 0 && cx < LEN)
		snprintf(buffer + cx, LEN-cx, ", and the half of that is %d.", 60/2/2);

	puts(buffer);

	return 0;
}
