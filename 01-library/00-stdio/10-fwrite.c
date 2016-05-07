// fwrite
// size_t fwrite(const void * ptr, size_t size, size_t count, FILE * stream)

#include <stdio.h>

int main(void)
{
	FILE * pf;
	char buffer[] = {'x', 'y', 'z'};

	pf = fopen("mylog.txt", "wb");
	fwrite(buffer, sizeof(char), sizeof(buffer), pf);
	fclose(pf);

	return 0;
}
