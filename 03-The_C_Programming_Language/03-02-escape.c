// 将字符串t复制到字符串s中，并在复制过程中将换行符
// 制表符等不可见字符分别转换为\n,\t等
#include <stdio.h>
#include <string.h>

#define STR_LEN		128

void un_escape(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while(t[i] != '\0')
	{
		switch(t[i])
		{
			case '\\':
				switch(t[i+1])
				{
					case 't':
						s[j] = '\t';
						break;
					case 'n':
						s[j] = '\n';
						break;
					default:
						s[j++] = '\\';
						s[j] = t[i+1];
						break;
				}
				i++;
				break;
			default:
				s[j] = t[i];
				break;
		}
		i++;
		j++;
	}
	s[j] = t[i];	// '\0'
}

void escape(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while(t[i] != '\0')
	{
		switch(t[i])
		{	
			case '\t':
				s[j++] = '\\';
			   	s[j++] = 't';
				break;
			case '\n':
			   	s[j++] = '\\';
			   	s[j++] = 'n';
				break;
			default:
				s[j++] = t[i];
				break;
		}
		i++;
	}
	s[j] = '\0';
}

void get_line(char t[], int n)
{
	int i;
	int c;

	for(i = 0; i < n - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		t[i] = c;

	t[i] = '\0';
}

int main(void)
{
	char s[STR_LEN];
	char t[STR_LEN];
	
	get_line(t, STR_LEN);
	printf("t = %s\n", t);
	escape(s, t);
	printf("s = %s\n", s);

	get_line(t, STR_LEN);
	printf("t = %s\n", t);
	un_escape(s, t);
	printf("s = %s\n", s);
}
