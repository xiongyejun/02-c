// time_t time(time_t * timer)
// get current time
//
#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t timer;
	struct tm y2k = {0};
	double seconds;

	y2k.tm_year = 100;
	y2k.tm_mday = 1;

	time(&timer);
	seconds = difftime(timer, mktime(&y2k));

	printf("%.f seconds since January 1, 2000 in the current timezone\n", seconds);

	return 0;
}
