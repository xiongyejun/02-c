// 编译命令 $ clang 13-curses.c -lcurses
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <curses.h>

int kbhit()
{
	int i;
	ioctl(0, FIONREAD, &i);
	return i;
}

int main(void)
{
	int i = 0;
	int c = ' ';

	initscr();	// 初始化curses函数
	cbreak();
	noecho();	//按键时不再屏幕上回显字符

	mvprintw(0, 0, "Press 'q' to quit\n");
	refresh();
	
	while('q' != c)
	{
		if(kbhit()){
			c = getch();
			mvprintw(1, 0, "got char '%c', on iteration %d\n", c, ++i);
		}
	}

	nocbreak();
	echo();
	endwin();
	return 0;
}
