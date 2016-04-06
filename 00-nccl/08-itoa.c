#include <stdio.h>

#define SWAP(a, b)		\
{						\
	char temp;			\
	temp = b;			\
	b = a;				\
	a = temp;			\
}

int main(void)
{
	int i = 0;
	int num = 123;
	char buf[10];
	printf("input a number");
	scanf("%d", &num);

	printf("num = %d\n", num);
	/* num 123 to string "123" */
	do{	
		buf[i] = num % 10 + '0';
		i++;

		num /= 10;
	}while (num !=0);

	buf[i] = '\0';

	for (int j = 0; j < i/2; j++){
		//void swap(char a, char b);
		SWAP(buf[j], buf[i-1-j]);
	}

	printf("buf = %s\n", buf);

	return 0;
}

void swap(char a, char b)
{
	char temp;
	temp = b;
	b = a;
	a = temp;
	return;
}
