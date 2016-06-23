// 定义宏swap(t,x,y) 以交换t类型的两个参数
#include <stdio.h>

#define swap(t,x,y)	t tmp; tmp = (x); (x) = (y); (y) = (tmp)

int main(void)
{
	int x = 1;
	int y = 2;

	printf("x = %d, y = %d\n", x, y);
	swap(int, x, y);
	printf("x = %d, y = %d\n", x, y);

	return 0;
}
