// int rename(const char * oldname, const char * newname)
// rename file
// changes the name of the file or directory specified by oldname to new name
// if the file is successfully renamed, a zero value is returned
// on failure, a nonzero value is returned

#include <stdio.h>

int main(void)
{
	int result;
	char oldname[] = "oldname.txt";
	char newname[] = "newname.txt";
	result = rename(oldname, newname);
	if(result == 0)
		puts("file successfully renamed");
	else
		perror("error renaming file");

	return 0;
}
