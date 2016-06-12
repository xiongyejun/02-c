// 将字符串s1中类似于a-z一类的速记符号
// 在字符串s2中扩展为等价的完整列表abc...xyz

#include <stdio.h>
#define STR_LEN			1024

int if_expand(char * s1, int i, char * s2, int j, int low, int high)
{
	int tmp;
	if(s1[i] >= low && s1[i+1] == '-' && s1[i+2] <=high && s1[i+2] > s1[i])
		for(tmp = s1[i]; tmp < s1[i+2]; tmp++) 
			// tmp不用<=s1[i+2]是为了处理a-b-c的情况,让i增长2
			s2[j++] = tmp;
	
	return j;
}

void expand(char * s1, char * s2)
{
	int i, j;
	int tmp_j;

	i = j = tmp_j = 0;
	while(s1[i] != '\0')
	{
		tmp_j = j; // 记录下j，后面判断是否进行了扩张
		j = if_expand(s1, i, s2, j, 'a', 'z');
		j = if_expand(s1, i, s2, j, 'A', 'Z');
		j = if_expand(s1, i, s2, j, '0', '9');

		if(j == tmp_j)
			s2[j++] = s1[i++];
		else
			i+=2;
	}
	s2[j] = s1[i];	// '\0'
}

int main(void)
{
	char s1[STR_LEN];
	char s2[STR_LEN];

	printf("input a str:");
	scanf("%s", s1);
	expand(s1, s2);

	printf("s1 = %s\n", s1);
	printf("s2 = %s\n", s2);

	return 0;
}
