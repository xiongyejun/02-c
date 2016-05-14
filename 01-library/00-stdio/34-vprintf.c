// int vprintf(const char * format, va_list arg)
//
#include <stdio.h>
#include <stdarg.h>

void write_formatted(const char * format, ...)
{
	va_list args;
	va_start (args, format);
	vprintf(format, args);
	va_end(args);
}

int main(void)
{
	write_formatted("call with %d variable argument.\n", 1);
	write_formatted("call with %d variable %s.\n", 2, "arguments");

	return 0;
}
