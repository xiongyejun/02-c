// 给指定后缀的文件添加序号
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>

#define SWAP(a, b)	\
{					\
	char temp;		\
	temp = b;		\
	b = a;			\
	a = temp;		\
}

int count = 0;
char buf[100];

//  将序号更改为 01-样式
void itoa(int num)
{
	int i = 0;
	int j = 0;

	buf[i++] = '-';
	for (j = 0; j < 2; i++, j++)
	{
		buf[i] = num % 10 + '0';
		num /= 10;
	}

	buf[i] = '\0';

	for (j = 0; j < i/2; j++)
		SWAP(buf[j], buf[i-1-j]);

}

/*
 * 扫描文件夹dir
 * 获取具有指定后缀p_suffix[]的文件
 * 然后重命名为01-mvxxxxx
 */
void scan_dir(char *dir, char * p_suffix[])
{
	DIR *dp;
	struct dirent *entry;

	if((dp = opendir(dir)) == NULL)
	{
		puts("cant't open dir");
		return;
	}

	chdir(dir);

	while ((entry = readdir(dp)) != NULL)
	{
		int state = 0;
		int i = 0;

		while (p_suffix[i])
		{
			if (strstr(entry->d_name, p_suffix[i++]) != NULL)
			{
				state = 1;
				count++;
				break;
			}
		}

		if (1 == state)
		{
			char * new;
			new = entry->d_name;
			if (entry->d_name[0] >= 48 && entry->d_name[0] <= 57 && entry->d_name[1] >= 48 && entry->d_name[1] <= 57 && entry->d_name[2] == '-')
				new+=3;	// 01-

			itoa(count);
			strcat(buf, new);
			
			if (strcmp(entry->d_name, buf) != 0)
			{
				if(0 == rename(entry->d_name, buf))		
				printf("rename:old=%s --> new=%s\n", entry->d_name, buf);
			}
		}
	}
	chdir("..");
	closedir(dp);

	return;
}

int main(void)
{
	char suffix[100];
	char *p_suffix[10];
	int i = 0;
	char delim = '|';
	char * dir = getcwd(dir, 100);

	printf("输入要添加序号的文件后缀，例如（.avi|.mv）:");
	scanf("%s", suffix);
	printf("suffix = %s\n", suffix);	
	
	p_suffix[i++] = strtok(suffix, &delim);
	while((p_suffix[i++] = strtok(NULL, &delim)));

	scan_dir(dir, p_suffix);

	return 0;
}
