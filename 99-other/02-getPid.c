#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1024

void getPidByName(pid_t *pid, char *task_name)
{
	DIR *dir;
	struct dirent *ptr;
	FILE *fp;
	char filepath[50];
	char cur_task_name[50];
	char buf[BUF_SIZE];

	dir = opendir("/proc");
	if (NULL != dir)
	{
		while ((ptr = readdir(dir)) != NULL)
		{
			if ((strcmp(ptr->d_name, ".") == 0) || (strcmp(ptr->d_name, "..") == 0))
					continue;

			if (DT_DIR != ptr->d_type)
				continue;

			sprintf(filepath, "/proc/%s/status", ptr->d_name); //生成要读取的文件路径
			fp = fopen(filepath, "r");
			if (NULL != fp)
			{
				if (fgets(buf, BUF_SIZE -1, fp) == NULL)
				{
					fclose(fp);
					continue;
				}
				sscanf(buf, "%*s %s", cur_task_name);

				//如果文件内容满足要求则打印路径的名字（即进程的PID)
				if (!strcmp(task_name, cur_task_name))
				{
					sscanf(ptr->d_name, "%d", pid);
				}
				fclose(fp);
			}
		}
		closedir(dir);
	}
}

void getNameByPid(pid_t pid, char *task_name)
{
	char proc_pid_path[BUF_SIZE];
	char buf[BUF_SIZE];

	sprintf(proc_pid_path, "/proc/%d/status", pid);
	FILE *fp = fopen(proc_pid_path, "r");
	if (NULL != fp)
	{
		if (fgets(buf, BUF_SIZE - 1, fp) == NULL)
		{
			fclose(fp);
		}
		fclose(fp);
		sscanf(buf, "%*s %s", task_name);
	}
}

int main(void)
{
	char task_name[50];
	pid_t pid = getpid();

	printf("pid of this process:%d\n", pid);

	void getNameByPid(pid_t pid, char *task_name);
	getNameByPid(pid, task_name);
	
	printf("getNameByPid:%s\n", task_name);

	void getPidByName(pid_t *pid, char *task_name);
	getPidByName(&pid, task_name);
	printf("getPidByName:%d\n", pid);
	//sleep(15);
	return 0;
}

