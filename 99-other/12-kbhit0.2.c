#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>

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

	system("stty raw -echo");
	printf("enter 'q' to quit\n");
	for(i = 0; c != 'q'; i++)
	{
		if(kbhit()){
			c = getchar();
			printf("got %c, on iteration %d\n", c, i);
		}
	}
	system("stty cooked echo");

	return 0;
}
