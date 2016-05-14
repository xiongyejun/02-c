// int vsprintf(char * s, const char * format, va_list arg)
// write formatted data from variable argument list to string

#include <stdio.h>
#include <stdarg.h>

void printf_error(const char * format, ...)
{
	char buffer[256];
	va_list args;
	va_start(args, format);
	vsprintf(buffer, format, args);
	perror(buffer);
	va_end(args);
}

int main(void)
{
	FILE * pf;
	char file_name[] = "myfile.txt";

	pf = fopen(file_name, "r");
	if(NULL == pf) printf_error("error opening '%s'", file_name);
	else
		fclose(pf);


	return 0;
}
