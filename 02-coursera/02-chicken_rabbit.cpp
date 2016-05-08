#include <iostream>
using namespace std;

int main()
{
	int i = 0;
	int n_cases, n_feet;

	cout << "input a number for loop:";
	cin >> n_cases;

	for(i = 0; i < n_cases; i++)
	{	
		cout << "input feets number:";
		cin >> n_feet;
		if(n_feet % 2 != 0)
			cout << "wrong:0 0" << endl;
		else if(n_feet % 4 != 0)
			cout << "min:" << n_feet /4 + 1 << " max:" << n_feet / 2 << endl;
		else
			cout << "min:" << n_feet / 4 << " max:" << n_feet / 2 << endl;
	}
	return 0;
}
