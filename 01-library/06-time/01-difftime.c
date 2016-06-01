// double difftime(time_t end, time_t beginning)
// return difference between two times
// the result of(end - beginning) in seconds as a floating-point
// value of type double
//
#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t now;
	struct tm newyear;
	double seconds;

	time(&now);// get current time; same as: now = time(NULL)
	newyear = *localtime(&now);
	newyear.tm_hour = 0;
	newyear.tm_min = 0;
	newyear.tm_sec = 0;
	newyear.tm_mon = 0;
	newyear.tm_mday = 1;

	seconds = difftime(now, mktime(&newyear));

	printf("%.f seconds since new year in the current timezone.\n", seconds);


	return 0;
}
