#include <stdio.h>
//#include <string.h>
#include <assert.h>
#define CONTAIN_OF_ZERO_BYTE(n)		(((n - 0x01010101) & (~n)) & 0x80808080)
#define TEST(n)			(((n-1) & (~n)) & 0x80)

char *mystrcpy3(char * dest, const char * src)
{
	char * p = dest;
	int * s;
	int * d;

	s = (int *)src;
	d = (int *)dest;
	while (1)
	{
		if (!CONTAIN_OF_ZERO_BYTE(*s))
		{
			printf("int *s is copied %x\n", *s);
			*d = *s;
			s++;
			d++;
			continue;
		}
		src = (char *)s;
		dest = (char *)d;

		while (*dest++ = *src++);
		break;
	}
	return p;
}

/*
char *mystrcpy(char * dest, const char * src)
{
	char * p = dest;
	int delta = dest - src;
#if 0
	if (dest == NULL || NULL == src)
	{
		printf("must be not NULL\n");
		return dest;
	}
#endif
	assert(dest != NULL && src != NULL);

// 1	while (*dest++ = *src++);
	while (*(char *)(src + delta) = *src++);	//Apple LLVM version 7.0.0 (clang-700.1.76) 没成功！

	return p;
}
*/

int main(void)
{
	char * p = NULL;

	char s1[16];
	char s2[16] = "hello123456789";
#if 0
	unsigned int n;
	for (n = 0x00; n <= 0xFF; n++)
	{
		printf("n = %x, TEST(n) = %x\n", n, TEST(n));
	}
	return 0;
#endif
	printf("1) s1 = %s\n", s1);
	char *mystrcpy3(char *, const char *);
	mystrcpy3(s1, s2);
	printf("2) s1 = %s\n", s1);



/*	char c;
	long addr;
	char * p;

//	printf("sizeof char * = %d\n", sizeof(p));
//	printf("sizeof long = %d\n", sizeof(addr));

	c = 'A';
	printf("c = %x\n", c);
	printf("&c = %p\n", &c);
	
	addr = (long)&c;
//	printf("addr = 0x%x\n", addr);

	p = (char *)0x1234; //&c;
	printf("p = %p\n", p);
    p = (char *)addr;	
	printf("*p = 0x%x\n", *p);
	printf("*addr = 0x%x\n", *(char *)addr);
*/
	return 0;
}
