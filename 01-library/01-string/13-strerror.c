// char * strerror(int errnum);
// get pointer to error message string
//
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void)
{
	FILE * pf;
	pf = fopen("unexist.ent", "r");
	if(NULL == pf)
		printf("error opening file unexist.ent: %s, errno = %d.\n", strerror(errno), errno);

	return 0;
}
