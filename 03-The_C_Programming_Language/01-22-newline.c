// 把较长的输入行折成短一些的两行或多行
#include <stdio.h>

#define N			20	// 输出的最长的行
#define MAX_LEN		256

int get_line(char str[], int len)
{
	int c, i;

	for(i = 0; i < len - 1 && (c = getchar()) != EOF && c !='\n'; i++)
		str[i] = c;

	if('\n' == c) str[i++] = c;
	str[i] = '\0';
	
	return i;
}
/*
 * 从begin开始打印str到end
 * 最后再打印一个/n
 */
void print_str(char str[], int begin, int end)
{
	while(begin <= end)
		putchar(str[begin++]);

	putchar('\n');
}
/* 
 * 查找第N列之前的最后一个非空格
 * 首先要找到一个空格，再往前找
 * 即要找到一个单词的结束
 * 如果没有空格或制表符就往后找，打印出来的行就超过N
 */
void find_last_unblank(char str[], int len, int begin)
{
	int i;
	int is_word_end;	// 初始-1，遇到空格为0，再遇到字符为1

	if(begin + N > len)
	{
		print_str(str, begin, len); 
		return;	// 不需要再拆分了
	}

	is_word_end = -1;
	for(i = begin + N; i >= begin; i--)
		if(-1 == is_word_end && (' ' == str[i] || '\t' == str[i]))
			is_word_end = 0;
		else
		if(0 == is_word_end && ' ' != str[i] && '\t' != str[i])
		{
			is_word_end = 1;
			break;
		}
	
	if(i >= begin)
	{
		print_str(str, begin, i);
		find_last_unblank(str, len, i+1);	// 递归
	}
	else	//  向后继续查找字符到空白处
	{
		i = begin + N + 1;
		while(str[i] != ' ' && str[i] != '\t' && i < len) i++;
		print_str(str, begin, i-1);
		find_last_unblank(str, len, i);
	}

}

int main(void)
{
	char str[MAX_LEN];
	int len;

	len = get_line(str, MAX_LEN);
	find_last_unblank(str, len, 0);

	return 0;
}

