// int mblen( const char * pmb, size_t max)
// get length of multibyte character
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void printbuffer(const char * pt, size_t max)
{
	int len;
	wchar_t dest;

	mblen(NULL, 0);
	mbtowc(NULL, NULL, 0);

	while(max > 0)
	{
		len = mblen(pt, max);
		if(len < 1) break;
		mbtowc(&dest, pt, len);
		printf("[%lc]", dest);
		pt+=len;
		max-=len;
	}
	printf("\n");
}

int main(void)
{
	int size;
	const char str[] = "test 这 只是 测试 string";

//	printbuffer(str, sizeof(str));
	size = strlen(str);
	printf("size = %d\n", size);

	setlocale(LC_ALL, "chinese-simplified");
	size = mblen(str, MB_CUR_MAX);
	printf("size = %d\n", size);
	


	return 0;
}
