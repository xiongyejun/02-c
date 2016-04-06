#include <stdio.h>
#include <math.h>

int main(void)
{
	int num = 100;
	int i = 0;
	int max = 0;

	printf("max prime \n");
	printf("input a value;");
	scanf("%d", &num);
	//printf("input a num:");
	//scanf("%d", &num);
	//从大到小判断也可以吧？`
	if (!(num % 2))
		num-=1;
	do
	{
		int tmp = sqrt(num);
		for (i = 2; i <= tmp; i++){
			if (num % i == 0){
#if DEBUG
				printf("num %d is not a prime\n", num);
#endif
				break;
			}
		}

		if (i == tmp + 1){
			max = num;
#if DEBUG
			printf("num %d is a prime\n", i );
#endif
		}
		
		num -= 2;	
	} while (0 == max);
	printf("max prime is %d\n", max);
	return 0;
}
