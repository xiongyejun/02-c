// fclose
// int fclose(FILE * stream);

#include <stdio.h>

int main(void)
{
	FILE * pf;
	// w是打开文件用户写入，一般缺省是以二进制写入
	// wt是打开文件以文本格式写入。
	pf = fopen("myfile.txt", "wt");
	fprintf(pf, "fclose example\n");
	fclose(pf);

	return 0;
}
