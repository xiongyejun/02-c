#include <stdio.h>

int get_input(char c)
{
	if (c == ' ') 
		return 1;
	return 0;
}

char c;
void act_print(void)
{

	printf("%c", c);
	return;
}

void act_null(void)
{
	return;
}

int state_transition[3][2] = 
{
	{0, 1},
	{0, 2},
	{0, 2}
};

typedef void (*PF)(void);
PF act_table[3][2] = 
{
	{act_print, act_print},
	{act_print, act_null},
	{act_print, act_null}
};

int main(void)
{
	int input = 0;
	int state = 0;

	while (EOF != c)
	{
		c = getchar();
		input = get_input(c);

		PF pf;
		pf = act_table[state][input];
		pf();	
		state = state_transition[state][input];	
	}

	return 0;	
}
