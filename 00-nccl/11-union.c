#include <stdio.h>

union test
{
	int n;
	unsigned char test[4];
	float f;
};

typedef union test test_t;

int main(void)
{
	int number;
	number = 0x12345678;
	test_t t;

	// little-endian: 0x78 56 34 12 
	// big-endian: 0x12 34 56 78
	//
/*	printf("does your machine use little-endian\n");
	printf("sizeof union = %ld\n", sizeof(union test));
	t.n = 0x12345678;
	t.f = 1.0;

	printf("test[0] = 0x%x\n", t.test[0]);
	printf("test[1] = 0x%x\n", t.test[1]);
	printf("test[2] = 0x%x\n", t.test[2]);
	printf("test[3] = 0x%x\n", t.test[3]);
	printf("t.n = 0x%x\n", t.n);
*/
	// 0x3f80 0000(int) = 1.0(float)
	t.n = 0x3f800000;
	printf("t.f = %f\n", t.f);

	return 0;
}
