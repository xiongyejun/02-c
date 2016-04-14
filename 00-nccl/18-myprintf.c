/*
 * Apple LLVM version 7.0.0 (clang-700.1.76)
 * Target: x86_64-apple-darwin15.4.0
 * Thread model: posix
 * 输出结果：
 * format = 0x103194f83
 * &int_a = 0x7fff5ca6bb74
 * &int_b = 0x7fff5ca6bb70
 * char_a = 0x103194f66
 * &int_c = 0x7fff5ca6bb64
 * char *  和 int 型参数地址完全不一样
 * 找不到规律
 * 无法实现函数
 * 不知道什么原因
 */


#include <stdio.h>
#include <string.h>

void myputs(char * buf)
{
	while (*buf)
		putchar(*buf++);
}

void itoa(int num, char * buf, int base)
{
	char * hex = "0123456789ABCDEF";
	int i = 0;
	int j = 0;

	do
	{
		int rest;
		rest = num % base;
		buf[i++] = hex[rest];
		num /= base;
	} while (num != 0);

	buf[i] = '\0';

#define SWAP(a, b)			\
	do						\
	{						\
		(a) = (a) ^ (b);	\
		(b) = (a) ^ (b);	\
		(a) = (a) ^ (b);	\
							\
	} while (0)		
	// reverse buf
	for (j = 0; j < i / 2; j++)
	{
		SWAP(buf[j], buf[i-1-j]);
	}

	return ;
}

int myprintf(const char * format, int int_a, int int_b, char * char_a, int int_c,...)
{
	printf("format = %p\n", format);
	printf("&int_a = %p\n", &int_a);
	printf("&int_b = %p\n", &int_b);
	printf("char_a = %p\n", char_a);
	printf("&int_c = %p\n", &int_c);
	
	return 0;
}

int test(int a, int b, int c, int d, ...)
{
	int * p;
	printf("&a = %p\n", &a);
	printf("&b = %p\n", &b);
	printf("&c = %p\n", &c);
	printf("&d = %p\n", &d);
	
	return 0;
}

int main(void)
{
	//test(100,200,300,400);
	char * p1 = "12345678911abc";
	char * p2 = "def";
	char * p3 = "asjflajfa";
	myprintf("a = %d, b = %x", 100, 300, p1, 400);

	return 0;
}
