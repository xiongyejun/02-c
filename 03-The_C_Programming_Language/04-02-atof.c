// 字符串转换为浮点数

#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[])
{
	double val, power;
	int i, sign;

	for(i = 0; isspace(s[i]); i++)
		;

	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;

	for(val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if(s[i] == '.')
		i++;

	for(power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}	
	val = sign * val / power;

	if((s[i] == 'e' || s[i] == 'E') && (s[i+1] == '-' || s[i+1] == '+') && isdigit(s[i+2]))
	{
		sign = s[i+1];
		i+=2;
		for(power = 0.0; isdigit(s[i]);i++)
			power = 10.0 * power + (s[i] - '0');

		if(sign == '-')
			val = val / pow(10.0, power);
		else
			val = val * pow(10.0, power);
	}

	return val;
}

int main(void)
{
	char s[80];

	printf("input a str:");
	scanf("%s", s);
	
	printf("s = %s, atof = %g\n", s, atof(s));

	return 0;
}
