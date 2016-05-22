// void * malloc(size_t size)
// allocate memory block
// the content of the newly allocated block of memory is not initialized
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, n;
	char * buffer;

	printf("how long do you want the string?");
	scanf("%d", &i);

	buffer =  (char *) malloc(i + 1);
	if(NULL == buffer) exit(1);

	for(n = 0; n < i; n++)
		buffer[n] = rand() % 26 +'a';
	buffer[n] = '\0';
	printf("Random string: %s\n", buffer);
	free(buffer);


	return 0;
}
