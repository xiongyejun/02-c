#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>

int main(void)
{
	wchar_t wc[] = L"abc我是谁hehe";
	setlocale(LC_ALL, "zh_CN");

	wprintf(L"%ls\n", wc);

	printf("char = %lu, wchar_t = %lu\n", sizeof(char), sizeof(wchar_t));
	return 0;
}
