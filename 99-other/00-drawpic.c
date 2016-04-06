#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define DIM 1024
#define _sq(x) ((x)*(x))
#define _cb(x) abs((x)*(x)*(x))
#define _cr(x) (unsigned char)(pow((x),1.0/3.0))

unsigned char RD(int, int);
unsigned char GR(int, int);
unsigned char BL(int, int);
void pixel_write(int , int);

unsigned char RD(int i, int j)
{
	return (char)(_sq(cos(atan2(j-512,i-512)/2))*255);
}

unsigned char GR(int i, int j)
{
	return (char)(_sq(cos(atan2(j-512,i-512)/2-2*acos(-1)/3))*255);
}

unsigned char BL(int i, int j)
{
	return (char)(_sq(cos(atan2(j-512,i-512)/2+2*acos(-1)/3))*255);
}

FILE *fp;
void pixel_write(int i, int j)
{
	static unsigned char color[3];
	color[0] = RD(i,j)&255;
	color[1] = GR(i,j)&255;
	color[2] = BL(i,j)&255;
	fwrite(color, 1, 3, fp);
}
int main(void)
{
	char pic_name[40] = "00-draw_pic.jpg";
	fp = fopen(pic_name, "wb");
	fprintf(fp, "P6\n%d %d\n255\n", DIM, DIM);
	for (int j = 0; j < DIM; j++)
		for (int i = 0; i < DIM; i++)
			pixel_write(i,j);

	fclose(fp);
	printf("OK\n");

	void open_pic(char pic_namep[]);
	open_pic(pic_name);
	return 0;
}

void open_pic(char pic_name[])
{
	char cmd[100];
	sprintf(cmd, "open %s", pic_name);
	system(cmd);
	return;
}
