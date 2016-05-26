/*
 * Apple LLVM version 7.0.0 (clang-700.1.76)
 * Target: x86_64-apple-darwin15.5.0
 * Thread model: posix
 */

#include <stdio.h>
#include <termios.h> //操作终端
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

#define ROW		20
#define COL		30
#define WALL	'$'
#define SPACE	' '
#define SNAKE	'@' 
#define FOOD	'*'

struct list{
	char * pos;
	struct list * next;
	struct list * prev;
};
typedef struct list list_t;

list_t * head;     // 头
list_t * tail;		// 尾
char direc;		// direction蛇当前的移动方向 a左 s下 d右 w上
char game[ROW][COL];	// 游戏大小
int len;				// 蛇的长度
int score;				// 得分
int sleep_time;			// 调节游戏速度的

// 网上找的代码kbhit
int kbhit(void)
{
	struct termios oldt, newt;
	int ch;
	int oldf;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);
	if(ch != EOF)
	{
		ungetc(ch, stdin);
		return 1;
	}
	return 0;
}

// 网上找的代码getch
char getch()
{
    int c=0;
    struct termios org_opts, new_opts;
    int res=0;
    //保留终端原来设置
    res=tcgetattr(STDIN_FILENO, &org_opts);
    assert(res==0);
    //从新设置终端参数
    memcpy(&new_opts, &org_opts, sizeof(new_opts));
    new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
    c=getchar();
    //恢复中断设置
    res=tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);assert(res==0);
    return c;
}

/*
 * 创建一个新的节点
 */
list_t * create_new_node(void)
{
	list_t * tmp;

	tmp = (list_t *) malloc(sizeof(list_t));
	if(NULL == tmp)
	{
		printf("create error\n");
		return NULL;
	}

	return tmp;
}

/*
 * 释放所有节点
 */
void free_node(void)
{
	list_t * p_next, * tmp;

	p_next = head->next;
	free(head);

	while(NULL != p_next)
	{
		tmp = p_next;
		p_next = p_next->next;
		free(tmp);
	}
}
/*
 * 生成食物
 */
void create_food()
{
	int space_count;
	int row, col, count;

	space_count = (ROW - 2) * (COL - 2) - len;
	space_count = rand() % (space_count + 1);
	count = 0;
	for(row = 1; row < ROW -1; row++)
		for(col = 1; col < COL -1; col++)
			if(SPACE == game[row][col])
			{
				count++;
				if(count == space_count)
				{
					game[row][col] = FOOD;
					return;
				}
			}

}

/*
 * 初始化
 */
void init_game(void)
{
	int row, col;
	list_t * tmp;

	for(row = 0; row < ROW; row++)
		for(col = 0; col < COL; col++)
			if(0 == row || ROW - 1 == row || 0 == col || COL - 1 == col)
				game[row][col] = WALL;
			else	
				game[row][col] = SPACE;

//	game[row / 2][3] = SNAKE;		// 蛇头
	head = create_new_node();
	head->pos = &game[row/2][3];
	*(head->pos) = SNAKE;
	head->prev = NULL;
	head->next = NULL;

//	game[row / 2][1] = SNAKE;		// 蛇尾
	tail = create_new_node();
	tail->pos = &game[row/2][1];
	*(tail->pos) = SNAKE;
	tail->next = NULL;
	tail->prev = NULL;

//	game[row / 2][2] = SNAKE;		// 蛇尾的前一个
	tmp = create_new_node();
	tmp->pos = &game[row/2][2];
	*(tmp->pos) = SNAKE;
	tmp->next = tail;
	tmp->prev = head;

	head->next = tmp;
	tail->prev = tmp;

	direc = 'd';
	create_food();

}

/*
 * 移动的前面是空白
 */
void move_if_SPACE(char * next_pos)
{
	list_t * tmp;
	// 蛇尾变成prev，蛇头head向前移动一个
	tmp = tail;
	*(tail->pos) = SPACE;
	tail = tail->prev;
	tail->next = NULL;

	tmp->next = head;
	tmp->pos = next_pos;
	*next_pos = SNAKE;
	//*(tmp->pos) = SNAKE;
	tmp->prev = NULL;
	head->prev = tmp;

	head = tmp;
}
/*
 * 移动的前面是食物
 */
void move_if_FOOD(char * next_pos)
{
	list_t * tmp;

	tmp = create_new_node();
	tmp->next = head;
	tmp->pos = next_pos;
	*next_pos = SNAKE;
	tmp->prev = NULL;
	head->prev = tmp;
	
	head = tmp;
	len++;
	score++;
	create_food();
}

/*
 * 蛇移动
 * 撞墙返回-1
 * 咬自己返回-2
 * 正常返回0
 * 吃到食物返回1
 */
int move(void)
{
	unsigned long step;
	char * next_pos;

	switch(direc)
	{
		case 'a': step = -sizeof(char); break;
		case 'd': step = sizeof(char); break;
		case 's': step = COL * sizeof(char); break;
		case 'w': step = -COL * sizeof(char); break;
		default:;
	}
	next_pos = (char *)((unsigned long)head->pos + step);

	switch (*next_pos)
	{
		case WALL : printf("猪撞墙上了！\n"); return -1; break;
		case SNAKE : printf("咬死自己了！\n"); return -2; break;
		case SPACE : move_if_SPACE(next_pos); return 0; break;
		case FOOD : move_if_FOOD(next_pos); return 1; break;
		default: return -3;
	}
}

int i = 0;
void print_game(void)
{
	int row, col;

	system("clear");
	printf("score:%5d\n\n", score);

	for(row = 0; row < ROW; row++)
	{
		for(col = 0; col < COL; col++)
			printf("%c", game[row][col]);

		printf("\n");
	}
}


int main(void)
{
	int state;
	char c;

	sleep_time = 1000 * 300; //1s = 1000ms  1ms = 1000us
	state = 0;
	len = 3;
	score = 0;
	init_game();
	while(0 <= state)
	{
		print_game();
		usleep(sleep_time);
		state = move();
		if(1 == kbhit()) 
		{
			c = getch();
			if('a' == c && 'd' != direc)
				direc = 'a';
			else
			if('s' == c && 'w' != direc)
				direc = 's';
			else
			if('d' == c && 'a' != direc)
				direc = 'd';
			else
			if('w' == c && 's' != direc)
				direc = 'w';
		}
		fflush(stdin);
	}
	free_node();
	
	return 0;
}
