/*
 * sum9-2.c	-	sumary how many digit from 1 to 100
 *
 * Author: xyj <244114746@qq.com>
 * Create Date: 2016-03-26
 * Revision 1.1
 *		+ debug printf		引入什么功能
 */
#include <stdio.h>

int main(void)
{
	int i = 0;
	int sum = 0;	/* the sumary of 9 */
	int max = 0;	/* the max number to count */
	int digit = 0;

	printf("please input a max   number:");
	scanf("%d", &max);
	printf("please input a digit number:");
	scanf("%d", &digit);
	int count(int ,int);
	
	/* sumary_9 from 0 to max  */
	for (i = 1; i <= max; i++){
			sum+= count(i, digit);
		}  
#if DEBUG
		printf("num = %d, counter = %d\n", i,  counter);
#endif
	printf("sum = %d\n", sum);
	return 0;
}

/*
 * count - counter how many digit in num
 * @num: the number from 1 to 100
 * @digit: digit can be 0, 1, 2, 3, ... 9
 *
 * return value: the counter of digit in this num
 */
int count(int num, int digit){
	int counter = 0;
	do{	
		if (num % 10 == digit){
			 counter++;
		}	 
		num /= 10;
	} while (num != 0);

	return counter;
}
