#include <iostream>
using namespace std;

int main()
{
	char i;
	int offset = 0;
	
	offset = 'A' - 'a';
	cout << offset << endl;

	for(i = 'a'; i <= 'z'; i++)
		cout << i << (char)(i + offset);

	cout << endl;
	return 0;
}
