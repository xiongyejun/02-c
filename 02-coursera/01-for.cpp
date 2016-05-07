#include <iostream>
using namespace std;

int main()
{
	int i = 0;
	cout << "within 20 odd:" << endl;

	for(i = 0; i < 20; i++)
	{
		if(i % 2 != 0)
			cout << i << endl;
	}
	return 0;
}
