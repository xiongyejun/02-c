// 一只大象口渴了，要喝20升水才能解渴，但现在只有一个深h厘米，底面半径为r厘米的小圆桶(h和r都是整数)。问大象至少要喝多少桶水才会解渴

#include <iostream>
using namespace std;

#define PI	3.14159

int main()
{
	int h, r;
	double volume;
	int n;

	cout << "input h and r:";
	cin >> h >> r;
	volume = PI * r * r * h / 1000;
	n = (int)(20 / volume);
	if((20 / volume - n) > 0) n += 1;

	cout << n << endl;

	return 0;
}
