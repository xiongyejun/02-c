// 从printf开始吧
// int printf(const char * format, ...);
// format	output							example
// d or i	signed decimal integer			392
// u		unsighed decimal integer		7235
// o		unsigned octal					610
// x		unsigned hexadecimal integer	7fa
// X		(uppercase)						7FA
// f		decimal floating point			392.65
// F		(uppercase)						392.65
// e		scientific notation(mantissa/
//			exponent),lowercase				3.9265e+2
// E		scientific notation(mantissa/
//			exponent),uppercase				3.9265E+2
// g		use the shortest 
//			representation: %e or %f		392.65
// G		use the shortest 
//			representation: %E or %F		392.65
// a		hexadcimal floating point		-0xc.90fep-2
// A		(uppercase)						-0XC.90FEP-2
// c		character						a
// s		string of characters			sample
// p		pointer address					b8000000
// n		nothing printed
// %		a % followed by another %
//			character will write a sigle
//			% to the stream					%
#include <stdio.h>

int main(void)
{
	int n = 0;

	printf("characters:%c %c \n", 'a', 65);
	printf("decimals:%d %ld\n", 1977, 650000L);
	printf("preceding with blanks: %10d\n", 1977);
	printf("preceding with zeros: %010d \n", 1977);
	printf("some different radices: %d %x %o %#x %#o \n",100, 100, 100, 100, 100);
	n = printf("floats: %4.2f %+.0e %E\n", 3.1416, 3.1416);
	printf("width trick: %*d \n", 15, 10);
	printf("string = %s\n", "astring");
	printf("n = %d\n", n);
	return 0;
}
