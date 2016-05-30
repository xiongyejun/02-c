// int isdigit(int c)
// check is character is decimal digit
// checks whether c is a decimal digit character
// decimal digits are any of: 0 1 2 3 4 5 6 7 8 9
//
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
	char str[] = "1776ad";
	int year;

	if(isdigit(str[0]))
	{
		year = atoi(str);
		printf("The year that folowed %d was %d.\n", year, year+1);
	}


	return 0;
}
