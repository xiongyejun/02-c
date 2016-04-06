#include <stdio.h>

//#define PRINT(x) printf("<debug>"  #x " = %d\n", x)
#define PRINT(x)

int main(void)
{
	int i = 0;
	int j = 0;

	printf("\nprint 9*9 multiplication table\n");
	
	for (i = 1; i < 10; i++){
		PRINT(i);
		for (j = 1; j <= i; j++){
			PRINT(j);
			printf("%d*%d=%2d ", j, i, i * j);
		}
		printf("\n");
	}
	
	return 0;
}
