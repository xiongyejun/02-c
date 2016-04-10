#include <stdio.h>

int get_input(char c)
{
	if (c == ' ') 
		return 1;
	return 0;
}

// delspace
int main(void)
{
	char buf[] = "   This is   a book.    That  is a bag\n";
	// input	  11100001001110100000111100001100101000	     
	// state	 012200001001220100000122200001200101000
	// print	  p  pppppppp  pppppppp   ppppp pppppppp
	
	int state = 0;
	printf("buf = %s\n", buf);

	char c = 'a';
	int i = 0;
	int input = 0;
	int words = 0;
	char * p = NULL;
	int counter = 0;

	//while ('\0' != c)
	while (EOF != c)
	{
		//c = buf[i++];
		c = getchar();
		input = get_input(c);
//		printf("c = %c, input = %d\n", c, input);

	// 0 0 -> 0
	// 0 1 -> 1
	// 1 0 -> 0
	// 1 1 -> 2
	// 2 0 -> 0
	// 2 1 -> 2
		if (state == 0 && input ==0)
		{
			state = 0;
			printf("%c", c);
		}
		else
		if (state == 0 && input == 1)
		{
			state = 1;
			printf("%c", c);
		}
		else
		if (state == 1 && input == 0)
		{
			state = 0;
			printf("%c", c);
		}
		else
		if (state == 1 && input ==1)
		{
			state = 2;
			// do nothing don't output
		}
		else
		if (state == 2 && input ==0)
		{
			state = 0;
			printf("%c", c);
		}
		else
		if (state == 2 && input == 1)
		{
			state = 2;
			// do nothing don't output
		}
		
	}

	return 0;	
}

/*
int main(void)
{
	char buf[] = "This is a book. That is a bag\n";
	// input     0111101101011110011
	// state	 0111101101011110011110110101110-1
	// words++		  ^  ^ ^    ^     ^  ^ ^   ^
	// print	  p
	//			  ++++p
	int state = 0;

	printf("buf = %s\n", buf);

	char c = 'a';
	int i = 0;
	int input = 0;
	int words = 0;
	char * p = NULL;
	int counter = 0;

	while ('\0' != c)
	{
		c = buf[i++];
		input = get_input(c);
//		printf("c = %c, input = %d\n", c, input);

		if (state == 0 && input ==0)
		{
			state = 0;
		}
		else
		if (state == 0 && input == 1)
		{
			state = 1;
			p = &buf[i-1];
			counter++;
		}
		else
		if (state == 1 && input == 0)
		{
			state = 0;
			words++;
			printf("word %d found!\n", words);
			for (int j = 0; j < counter; j++)
				printf("%c", p[j]);
			printf("\n");
			counter = 0;
		}
		else
		if (state == 1 && input ==1)
		{
			state = 1;
			counter++;
		}
		
	}

	printf("there is %d words found!\n", words);
	return 0;	
}
*/

