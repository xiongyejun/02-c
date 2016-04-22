// 修改当前文件夹下文件的名称，仅是删除文件名中部分特殊字符
#include <fcntl.h>		// 提供open()函数
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>		// 提供目录流操作函数
#include <string.h>
#include <sys/stat.h>	// 提供属性操作函数
#include <sys/types.h>  // 提供mode_t 类型
#include <stdlib.h>
#include <unistd.h>		//包含了Linux C 中的函数getcwd()

#define MAX 200	// txt的长度
#define FILES 20	// 文件夹中的文件个数
//#define PRINT(s)	printf(#s " = %s\n", s)
int count = 0;
char * p[20];// 替换的字符
int n;			//替换的数组个数

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

	int i;
	int sign = 0;
	for (i = 0; i < n; i += 2)
	{
		if (strcmp("space", p[i+1]) == 0)
			p[i+1] = "";

		sign += replace(file, p[i], p[i+1]);
	}

	if (sign > n / 2 * -1)
	{
		if (0 == rename(old, file))
		{
			printf("rename:old = %s --> new = %s\n", old, file);
			count++;
		}
	}
}


/* 遍历dir*/
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
		if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 && strcmp(entry->d_name, "a.out") != 0 && strcmp(entry->d_name, ".DS_Store") != 0 )
			my_rename(entry->d_name);
	
	}
	chdir("..");		// 回到上级目录
	closedir(dp);

}

void get_replace_str(char str_replace[])
{
	FILE * fp = fopen("/Users/xiongyejun/Downloads/str_replace.txt", "r");
	if (fp == NULL)
	{
		puts("no such file");
		return;
	}
	
	fgets(str_replace, MAX, fp);
	str_replace[strlen(str_replace) - 1] = '\0';
	fclose(fp);
}

int main(void)
{
	char * dir = getcwd(dir , 100); //"/Users/xiongyejun/Downloads"; 

	int i = 0;
	char * delim = "|";
	char str_replace[MAX];
	get_replace_str(str_replace);
	p[i++] = strtok(str_replace, delim);

	while ((p[i++] = strtok(NULL, delim)));
	n = i - 1;
	scan_dir(dir);
	//for (j = 0; j< i - 1; j++)
	//	printf("%s\n", p[j]);

	printf("%d files rename over.\n", count);
	return 0;
}

