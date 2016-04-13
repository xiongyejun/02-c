#include <stdio.h>
#include <string.h>

#define PRINT(s)		printf(#s " = %s\n", s)
#define MAX 20	//des的最大个数

/* str_split 
 * 将src原数据
 * 按delim进行分隔
 * 放入des[]数组
 * 返回数组个数
 */

int str_split(char * src, char * delim, char * des[])
{
	char * find_pos;
	int des_count = 0;
	int str_len = strlen(delim);

	find_pos = strstr(src, delim);		//查找第一个dilim在src中的指针位置
	while (find_pos)
	{
		des[des_count++] = src;	
		src = find_pos;					//src向后移到find_pos位置
		memset(src, '\0', str_len);		//将dilim替换为'\0'
		src = &src[str_len];			//src继续向后移动
		find_pos = strstr(src, delim);	//查找后面的dilim
	}
	
	des[des_count] = src;				//最后一个放入数组
	
	return des_count;
}

int main(void)
{
	char src[] = "fla-+1-+3-+js-+d-+a-d+fsdlj-+ldsjflaj-+jfasdjf";
	char * delim = "-+";
	char * des[MAX];

	PRINT(src);	
	int count = str_split(src, delim, des);

	for (int i = 0; i <= count; i++)
		printf("%s\n", des[i]);
/*
	char c[] = "ab-de-gwd-bfw---sdfa";
	char * delim = "-";
	char * p[10];
	int i = 0;

	printf("c = %s\n", c);	
	p[i++] = strtok(c, delim);

	while ((p[i++] = strtok(NULL, delim)));

	for (int j = 0; j < i - 1; j++)
		printf("%s\n", p[j]);
*/	
	return 0;
}
