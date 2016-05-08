// 百元买白鸡
// x + y + z = 100
// 3x + 2y + 0.5z = 100

#include <iostream>
using namespace std;

int main()
{
	int x = 0, y = 0, z = 0;

	for(x = 0; x <= 33; x++)
		for(y = x; y <= 50; y++)
		{
			z = 100 - y - x;
			if(100 == (3 * x + 2 * y + 0.5 * z))
				cout << "x=" << x << " y=" << y << " z=" << z << endl;
		}

	return 0;
}

