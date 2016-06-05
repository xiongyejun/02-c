#include <stdio.h>
#include <limits.h>

int main(void)
{
	signed char signed_c; unsigned char unsigned_c;
	signed short int signed_short_i; unsigned short int unsigned_short_i;
	signed int signed_i; unsigned int unsigned_i;
	signed long int signed_long_i; unsigned long int unsigned_long_i;

	printf("Sizeof(char) = %ld\n", sizeof(char));
	signed_c = 0x7F; // 01111 1111
	printf("signed char max = %d\t", signed_c);
	signed_c = 0x80; // (128)1000 0000 反码0111 1111 补码1000 0000
	printf("signed char min = %d\n", signed_c);
	unsigned_c = 0xFF; // 11111 1111
	printf("unsigned char max = %d\t", unsigned_c);
	unsigned_c = 0x00; 
	printf("unsigned char min = %d\n\n", unsigned_c);

	printf("Sizeof(short int) = %ld\n", sizeof(short int));
	signed_short_i = 0x7FFF; // 01111 1111 1111 1111
	printf("signed short int max = %d\t", signed_short_i);
	signed_short_i = 0x8000; // 1000 0000 0000 0000 反码0111 1111 1111 1111补码1000 0000 0000 0000
	printf("signed short int min = %d\n", signed_short_i);
	unsigned_short_i = 0xFFFF; // 11111 1111
	printf("unsigned short int max = %d\t", unsigned_short_i);
	unsigned_short_i = 0x0000; 
	printf("unsigned short int min = %d\n\n", unsigned_short_i);

	printf("Sizeof(int) = %ld\n", sizeof(int));
	signed_i = 0x7FFFFFFF;
	printf("signed int max = %d\t", signed_i);
	signed_i = 0x80000000;
	printf("signed int min = %d\n", signed_i);
	unsigned_i = 0xFFFFFFFF; 
	printf("unsigned int max = %u, UINT_MAX = %u\t", unsigned_i, UINT_MAX);
	unsigned_i = 0x00000000; 
	printf("unsigned int min = %u\n\n", unsigned_i);

	printf("Sizeof(long) = %ld\n", sizeof(long));
	signed_long_i = 0x7FFFFFFFFFFFFFFF;
	printf("signed long int max = %ld\t", signed_long_i);
	signed_long_i = 0x8000000000000000;
	printf("signed long int min = %ld\n", signed_long_i);
	unsigned_long_i = 0xFFFFFFFFFFFFFFFF; 
	printf("unsigned long int max = %lu, ULONG_MAX = %lu\t", unsigned_long_i, ULONG_MAX);
	unsigned_long_i = 0x0000000000000000; 
	printf("unsigned long int min = %lu\n\n", unsigned_long_i);


	return 0;
}
