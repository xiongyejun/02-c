#include <stdio.h>
#include <math.h>

struct point
{
	float x;
	float y;
	int test[100];
};

typedef struct point point_t;

int main(void)
{
	float x, y;
	point_t p2 = {1.0, 2.0};
	point_t p; 
	float distance;

	printf("demo structure\n");

	printf("input two float separated by spaces:");
	scanf("%f %f", &p.x, &p.y);

	printf("p.x = %f, p.y = %f\n", p.x, p.y);
	printf("p2.x = %.1f, p2.y = %.2f\n", p2.x, p2.y);

	printf("<debug1> &p = %p\n", &p);

	float calculate(struct point p,struct point p2);
	distance = calculate(p, p2);
	printf("distance = %f\n", distance);

	return 0;
}

float calculate(point_t p, point_t p2)
{
	float dx, dy;
	
	printf("<debug2> &p = %p\n", &p);
	dx = p.x - p2.x;
	dy = p.y - p2.y;
	return sqrt(dx * dx + dy * dy);
}
