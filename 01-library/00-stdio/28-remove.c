// int remove(const char * filename)
// remove file
// if the file is successfully deleted, a zero value is returned
// on failure, a nonzero value is returned

#include <stdio.h>

int main(void)
{
	if(remove("myfile.txt") != 0)
		perror("error deleting file");
	else
		puts("file successfully delete");

	return 0;
}
