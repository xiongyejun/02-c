// int strcoll(const char 8 str1, const char * str2)
// compare two strings using locale
// strcoll()会依环境变量LC_COLLATE所指定的文字排列次序来比较s1和s2 字符串。
// 若LC_COLLATE为"POSIX"或"C"，则strcoll()与strcmp()作用完全相同。

#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[] = "abcdef";
	char str2[] = "abCdef";

	printf("strcoll(%s, %s) = %d, strcoll(%s, %s) = %d\n", str1, str2, strcoll(str1,str2), str2, str1, strcoll(str2, str1));

	return 0;
}
