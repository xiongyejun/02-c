// int mbtowc(wchar_t * pwc, const char * pmb, size_t max_
// concvert multibyte sequence to wide character
//
//
#include <stdio.h>
#include <stdlib.h>

void print_buffer(const char * pt, size_t max)
{
	int len;
	wchar_t dest;
	
	mbtowc(NULL, NULL, 0);	// reset mbtowc

	while(max > 0)
	{
		len = mbtowc(&dest, pt, max);
		printf("len = %d\n", len);
		if(len < 1) break;
		printf("[%lc]", dest);
		pt+=len;
		max-=len;
	}
}
	
int main(void)
{
	const char str[] = "mbtowc 我时候 example";

	print_buffer(str, sizeof(str));


	return 0;
}
