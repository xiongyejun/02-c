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

#include <stdarg.h>
/*
 * va_list xxx;
 * va_start()
 * va_arg()
 * va_end()
 */
static char buf[100];
int myprintf(const char * format, ...)
{	
	va_list p;
	char c;
	int value = 0;

	va_start(p, format);

	while ((c = *format++) != '\0')
	{
		if (c != '%')
		{
			putchar(c);
			continue;
		}
		else
		{
			c = *format++;
			if (c == 's')
			{
				//value = va_arg(p, char *);
				myputs(va_arg(p, char *));
			}
			if (c == 'c')
			{
				//value = (int)va_arg(p, char);
				//putchar((char)value);
				putchar(va_arg(p, int));
			}
			if (c == 'x')
			{
				value = va_arg(p, int);
				itoa(value, buf, 16);
				myputs(buf);
				
			}
			if (c == 'd')
			{
				//value = *p++;
				value = va_arg(p, int);
				itoa(value, buf, 10);
				myputs(buf);
			}
		}
	}
	va_end(p);	
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
	myprintf("a = %d, b = %d, c = %s, d = %d, e = %s, f = %s\n", 100, 300, p1, 400, p2, p3);

	return 0;
}
