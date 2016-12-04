#include <stdio.h>

int main(void)
{
	unsigned int n;

	n = 120304;

	printf("n = %d\n", n);
	void print_out(unsigned int n);	
	print_out(n);	
	return 0;
}	

void print_out(unsigned int n)
{
	if(n >= 10)
		print_out(n / 10);

	printf("%d\n", n % 10);
}
