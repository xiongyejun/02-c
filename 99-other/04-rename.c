// 修改当前文件夹下文件的名称，仅是删除文件名中部分特殊字符
#include <fcntl.h>		// 提供open()函数
#include <stdio.h>
#include <dirent.h>		// 提供目录流操作函数
#include <string.h>
#include <sys/stat.h>	// 提供属性操作函数
#include <sys/types.h>  // 提供mode_t 类型
#include <stdlib.h>
#include <unistd.h>		//包含了Linux C 中的函数getcwd()

int count = 0;

int replace(char *src, char *str_match, char *str_replace)
{
	int str_len;
	char str_new[100];

	char *find_pos = strstr(src, str_match);
	if ((!find_pos) || (!str_match))
		return -1;

//	puts(src);
	while (find_pos)
	{
		memset(str_new, 0, sizeof(str_new));
		str_len = find_pos - src;
		strncpy(str_new, src, str_len);
		strcat(str_new, str_replace);
		strcat(str_new, find_pos + strlen(str_match));
		strcpy(src, str_new);

		find_pos = strstr(src, str_match);
	}
	
//	puts(src);
	return 0;
}

void my_rename(char *file)
{
	char old[100];
	memset(old, 0, sizeof(old));
	strncpy(old, file, strlen(file));

	int n = 6;
	char *c[n];
	int i;
	c[0] = "[阳光电影www.ygdy8.com].";
	c[1] = "HD.720p.";
	c[2] = "国语中字.";
	c[3] = "国粤双语中字.";
	c[4] = "国法双语中字.";
	c[5] = "BD.720p.";

	int sign = 0;
	for (i = 0; i < n; i++)
	{
		sign +=replace(file, c[i], "");
	}	

	if (sign > n * -1)
	{
		if (0 == rename(old, file))
		{
			printf("rename:old = %s --> new = %s\n", old, file);
			count++;
		}
	}
}

void scan_dir(char *dir)
{
	DIR *dp;						// 定义子目录流指针
	struct dirent *entry;			// 定义dirent结构指针保存后续目录

	if ((dp = opendir(dir)) == NULL)
	{
		puts("can't open dir.");
		return;
	}

	chdir(dir);						// 切换到当前目录
	while ((entry = readdir(dp)) != NULL)	//  获取下一级目录信息
	{
		my_rename(entry->d_name);
	}
	chdir("..");		// 回到上级目录
	closedir(dp);
}

int main(void)
{
	char *dir; // = "/Users/xiongyejun/01-GitHub/02-c";
	getcwd(dir,80);
	
	scan_dir(dir);
	printf("%s:%d files rename over.\n", dir, count);
	return 0;
}

