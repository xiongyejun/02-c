#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define a0 act_print_word
#define a1 act_save_to_buf
#define a2 act_print_buf_and_word 
#define a3 act_save_word
#define a4 act_get_macro_name
#define a5 act_get_macro_value
#define a6 act_null

#define debug(fmt, args...) fprintf(stderr, fmt, ##args)

struct macro
{
	char name[64];
	char value[64];

} macros[16];
int macro_counter = 0;

int get_input(char * word)
{
	if (strcmp(word, " ") == 0) 
		return 0;
	if (strcmp(word, "\t") == 0) 
		return 0;
	if (strcmp(word, "#") == 0) 
		return 1;
	if (strcmp(word, "define") == 0) 
		return 2;
	if (strcmp(word, "\n") == 0) 
		return 4;

	return 3;
}

char c;
char word[64];
char word_buf[64];
char buf[128];

void act_print_word(void)
{
	int i = 0;
	for (i = 0; i < macro_counter; i++)
	{
		if (strcmp(word, macros[i].name) == 0)
		{	
			printf("%s", macros[i].value);
			return;
		}
	}
	printf("%s", word);

	return;
}

void act_save_to_buf(void)
{
	strcat(buf, word);
	return;
}

void act_print_buf_and_word(void)
{
	printf("%s", buf);
	printf("%s", word);
	
	return;
}

void act_save_word(void)
{
	strcat(word_buf, word);
	return;
}

void act_get_macro_name(void)
{
	strcpy(macros[macro_counter].name, word_buf);
	strcpy(word_buf, "");
	debug("name = %s\n", macros[macro_counter].name);
	return;
}

void act_get_macro_value(void)
{
	strcpy(macros[macro_counter].value, word_buf);
	strcpy(word_buf, "");

	debug("value = %s\n", macros[macro_counter].value);
	macro_counter++;
	return;
}

void act_null(void)
{
	return;
}

/* state machine design */
#if 0
i0: space & tab
i1: #
i2: define
i3: anyword (MAX)
i4: \n

a0 act_print_word
a1 act_save_to_buf
a2 act_print_buf_and_word 
a3 act_save_word
a4 act_get_macro_name
a5 act_get_macro_value
a6 act_null

#define MAX  100
	spa		#		def		MAX		\n
	i0		i1		i2		i3		i4
------------------------------------------
s0: start	
	s0		s1		s0		s0		s0
	a0		a1		a0		a0		a0

s1: #
	s1		s0		s2		s0		s0
	a1		a2		a1		a2		a2

s2: #define
	s3		s0		s0		s0		s0		
	a1		a2		a2		a2		a2

s3: #define |
	s3		s4		s4		s4		s0
	a1		a3		a3		a3		a2

s4: #define MAX
	s5		s5		s4		s4		s0	
	a4		a4		a3		a3		a5

s5: #define MAX |
	s5		s6		s6		s6		s0	
	a6		a3		a3		a3		a5

s6:	#define MAX 1
	s6		s6		s6		s6		s0
	a3		a3		a3		a3		a5

#endif

typedef void (*PF)(void);
PF act_table[7][5] = 
{
	a0,		a1,		a0,		a0,		a0,
	a1,		a2,		a1,		a2,		a2,
	a1,		a2,		a2,		a2,		a2,
	a1,		a3,		a3,		a3,		a2,
	a4,		a4,		a3,		a3,		a5,
	a6,		a3,		a3,		a3,		a5,
	a3,		a3,		a3,		a3,		a5,
};

enum {s0 = 0, s1, s2, s3, s4, s5, s6};
int state_transition[7][5] = 
{
	s0,		s1,		s0,		s0,		s0,
	s1,		s0,		s2,		s0,		s0,
	s3,		s0,		s0,		s0,		s0,		
	s3,		s4,		s4,		s4,		s0,
	s5,		s5,		s4,		s4,		s0,	
	s5,		s6,		s6,		s6,		s0,	
	s6,		s6,		s6,		s6,		s0,
};

void getword(char * word)
{	
	char c;
	
	c = getchar();

	if (c == EOF)
	{
		*word = '\0';
		return;
	}	

	// if c == 1
	if (!isalpha(c))
	{
		*word++ = c;
		*word = '\0';
		return;
	}

	do
	{
		*word++ = c;
		c = getchar();
	} while (isalnum(c) || c == '_');
	// current c is $
	
	ungetc(c, stdin);
	*word = '\0';

	return;
}

int main(void)
{
	int input = 0;
	int state = 0;
	void (*pf)(void); //PF pf;
	
	while (1)
	{
		getword(word);
		input = get_input(word);
		
		if (strcmp(word, "") == 0)
			break;

		pf = act_table[state][input];
		pf();	
		state = state_transition[state][input];	

		debug("word = <%s>, input = %d, state = %d\n", word, input, state);
	}

	return 0;	
}
