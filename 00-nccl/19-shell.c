#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int (*pf)(int, int);
char opchar;
int power(int a, int b)
{
	int result = 1;
	int i;
	for (i = 0; i<b; i++)
		result *= a;

	return result;
}
int mul(int a, int b)
{
	return a*b;
}

int my_div(int a, int b)
{
	if (b != 0)
		return a/b;

	return -1;
}

int add(int a, int b)
{
	return a+b;
}

int sub(int a, int b)
{
	return a-b;
}

int math_main(int argc, char * argv[])
{
	int a, b;
	int result;

	if (argc < 3)
	{
		printf("argc = %d, para is too few\n", argc);
		return -1;
	}
	if (pf == NULL)
	{
		printf("input error\n");
		return -1;
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);

	result = pf(a, b);
	printf("result: %s %c %s = %d\n",argv[1], opchar, argv[2], result);
	return 0;
}

#if 0
int sub_main(int argc, char * argv[])
{
	int a, b;

	if (argc < 3)
	{
		printf("argc = %d, para is too few\n", argc);
		return -1;
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);

	printf("add result: %s - %s = %d\n", argv[1], argv[2], a-b);
	return 0;
}

int add_main(int argc, char * argv[])
{
	int a, b;

	if (argc < 3)
	{
		printf("argc = %d, para is too few\n", argc);
		return -1;
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);

	printf("add result: %s + %s = %d\n", argv[1], argv[2], a+b);
	return 0;
}
#endif

struct operation
{
	char name[8];
	int (*pf)(int, int);
	char opchar;
} op[] = 
{
	{"add", add, '+'},
	{"sub", sub, '-'},
	{"mul", mul, '*'},
	{"div", my_div, '/'},
	{"power", power, '^'}
};
int command_do(int argc, char * argv[])
{
#if 0
	if (strcmp(argv[0], "add") == 0)
		//add_main(argc, argv);
		pf = add;

	if (strcmp(argv[0], "sub") == 0)
		//sub_main(argc, argv);
		pf = sub;
#endif
	pf = NULL;
	for (int i = 0; i < sizeof(op) / sizeof(op[0]); i++)
	{
		if (strcmp(argv[0], op[i].name) == 0)
		{
			opchar = op[i].opchar;	
			pf = op[i].pf;
			break;
		}
	}
	math_main(argc, argv);
	return 0;
}

void shell_parse(char * buf)
{
	int argc = 0;
	char * argv[8];
	int state = 0;
	int i = 0;

	while (*buf)
	{
		char c = *buf;
		if (c == ' ' && state == 0)
			state = 0;
		else
		if (c != ' ' && state == 0) // 找到第一个字符
		{	
			argv[argc++] = buf;
			state = 1;
		}
		else
		if (c == ' ' && state == 1) // 单词结尾
		{
			*buf = '\0';
			state = 0;
		}
		else
		if (c != ' ' && state == 1)
		{
			state = 1;
		}
		buf++;
		if (*buf == '\n')
			*buf = '\0';
	}

	argv[argc] = NULL;
	printf("argc = %d\n", argc);
	for (i = 0; i <= argc; i++)
		printf("argv[%d] = %s\n", i, argv[i]);

	command_do(argc, argv);

}

// int main(void)
// int main(int argc, char *argv[])
int main(int argc, char *argv[], char * env[])
{
	int i = 0;
	char buf[64];

	printf("demo argc & argv\n");
	
	//scanf("%s", buf);
	//gets(buf);	// 不会检查越界
	while (1)
	{
		printf("# ");
		fgets(buf, 64, stdin);
		printf("buf = %s\n", buf);

		shell_parse(buf);
	}
#if 0
	for (i = 0; i <= argc; i++)
		printf("argv[%d] = %s\n", i, argv[i]);
	
	for (i = 0; i <= 5; i++)
		printf("env[%d] = %s\n", i, env[i]);
#endif
	return 0;
}

