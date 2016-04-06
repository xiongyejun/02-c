#include <stdio.h> 

enum day
{
	MONDAY = 1,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY	
};
int main(void)
{
	char car_num_str[8] = "A12345";
	int tail_num = 0;		// "a12345" -> 5
	enum day today = MONDAY;		// 1-7
	char last_char;
	int ret;

	printf("Please input your car number:\n");
	scanf("%s", car_num_str);
	printf("car num is %s\n", car_num_str);
	
	// get the last_char of car
	char get_last_char(char c[]);
	last_char = get_last_char(car_num_str);
	printf("last_char is %c\n", last_char);

	tail_num = last_char - '0';
	
	int is_restricted(int i, enum day);
	ret = is_restricted(tail_num, today);

	if (1 == ret)
		printf("restricted!\n");
	else
		printf("not restricted!\n");
	
	enum day get_week_day(int, int ,int );
	today = get_week_day(2016, 03, 28);
	printf("today = %d\n", today);

	return 0;
}

int is_restricted(int tail_num, enum day today)
{
	// tail_num : 0, 1, ... 9
	// 0, 5
	// 0, 6
	// ...
	//
	int ret = 0;

	switch (tail_num)
	{
		case 0:
		case 5:
			if (today == MONDAY)
				ret = 1;
			else
				ret = 0;

			break;
		case 1:
		case 6:
			ret = (today == TUESDAY) ? 1 : 0;
			break;
		case 2:
		case 7:
			ret = (today == WEDNESDAY) ? 1 : 0;
			break;
		case 3:
		case 8:
			ret = (today == THURSDAY) ? 1 : 0;
			break;
		case 4:
		case 9:
			ret = (today == FRIDAY) ? 1 : 0;
			break;
		default:
			ret = 0;
			break;
	}

	return ret;
}

char get_last_char(char str[])
{
	char c;
	int i = 0;

	while (str[i])
	{
		c = str[i];
		i++;
	}
	return c;
}

enum day get_week_day(int year, int month, int day)
{
	// 20160101 : week day 5
	int m[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	int alldays = 0;

	for (int i = 1; i < month; i++)
	{
		alldays += m[i-1];
	}

	alldays += day - 1;
	
	
	switch ((alldays + 5) % 7)
	{
		case 0:
			return SUNDAY;
		case 1:
			return MONDAY;
		case 2:
			return TUESDAY;
		case 3:
			return WEDNESDAY;
		case 4:
			return THURSDAY;
		case 5:
			return FRIDAY;
		case 6:
			return SATURDAY;
	}

	return MONDAY;
}
