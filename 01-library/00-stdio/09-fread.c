// fread
// size_t fread(void * ptr, size_t size, size_t count, FILE * stream)

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE * pf;
	long lSize;
	char * buffer;
	size_t result;

	pf = fopen("mylog.txt", "rb");
	if(NULL == pf)
	{
		fputs("File error", stderr);
		exit(1);
	}

	fseek(pf, 0, SEEK_END);
	lSize = ftell(pf);
	rewind(pf);

	buffer = (char *) malloc(sizeof(char) * lSize);
	if(NULL == buffer)
	{
		fputs("Memory error", stderr);
		exit(2);
	}

	result = fread(buffer, 1, lSize, pf);
	if(result != lSize)
	{
		fputs("Reading error", stderr);
		exit(3);
	}
	else
		printf("%s\n", buffer);

	fclose(pf);
	free(buffer);

	printf("lSize = %ld, siezeof size_t = %ld, sizeof char = %ld\n", lSize, sizeof(size_t), sizeof(char));

	return 0;
}
