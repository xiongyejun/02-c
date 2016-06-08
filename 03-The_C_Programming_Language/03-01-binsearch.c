// 折半查找
#include <stdio.h>

#define V_LEN		10

int binsearch_ans_3(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n-1;

	while(low < high)
	{
		mid = (low + high) / 2;
		if(v[mid] >= x)
			high = mid;
		else
			low = mid + 1;
	}
	return (x == v[low]) ? low : -1;
}

int binsearch_ans_2(int x, int v[], int n)
{
	int low, high, mid;
	low = -1;
	high = n;

	while(low + 1 < high)
	{
		mid = (low + high) / 2;
		if(v[mid] < x)
			low = mid;
		else
			high = mid;
	}
	if(high == n || v[high] != x)
		return -1;
	else
		return high;
}

int binsearch_ans(int x, int v[], int n)
{
	int low, high, mid;

	low = mid = 0;
	high = n - 1;

	mid = (low + high) / 2;
	while(low <= high && v[mid] != x)
	{
		if(x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
		mid = (low + high) / 2;
	}

	if(v[mid] == x) return mid;

	return -1;
}
/*
 * x: 待查找元素
 * v: 数组
 * n: 数组元素个数
 * 返回x所在元素的下标
 */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = mid = 0;
	high = n - 1;

	while(low <= high && v[mid] != x)
	{
		mid = (low + high) / 2; // 应当先计算mid，要不然先比较的就是v[0],不符合折半查找的思想
		if(x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

	if(v[mid] == x) return mid;

	return -1;
}

int main(void)
{
	int v[V_LEN] = {-1,1,3,5,7,9,11,13,15,17};
	int x;
	int k;

	x = 5;
	k = 0;

	printf("input a number:");
	scanf("%d", &x);

	printf("v = ");
	for(k = 0; k < V_LEN; k++)
		printf("%2d ", v[k]);
	putchar('\n');


	k = binsearch(x, v, V_LEN);
	if(-1 == k)
		printf("1 the number %d is not in the v\n", x);
	else
		printf("1 the number %d in the v is %d\n", x, k);

	k = binsearch_ans(x, v, V_LEN);
	if(-1 == k)
		printf("2 the number %d is not in the v\n", x);
	else
		printf("2 the number %d in the v is %d\n", x, k);

	k = binsearch_ans_2(x, v, V_LEN);
	if(-1 == k)
		printf("3 the number %d is not in the v\n", x);
	else
		printf("3 the number %d in the v is %d\n", x, k);

	k = binsearch_ans_3(x, v, V_LEN);
	if(-1 == k)
		printf("4 the number %d is not in the v\n", x);
	else
		printf("4 the number %d in the v is %d\n", x, k);

	return 0;
}
