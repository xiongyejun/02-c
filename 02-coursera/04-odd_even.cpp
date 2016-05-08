#include <iostream>
using namespace std;

int main()
{
	int all[10], odd[10], even[10];
	int i = 0;
	int i_odd = 0, i_even = 0;

	cout << "input 10 numbers:" << endl;
	for(i = 0; i < 10; i++)
	{
		cin >> all[i];
		if(all[i] % 2 == 0)
			even[i_even++] = all[i];
		else
			odd[i_odd++] = all[i];
	}

	cout << "odd:";
	for(i = 0; i < i_odd; i++)
		cout << odd[i] << " " ;
	cout << endl << "even:";
	for(i = 0; i < i_even; i++)
		cout << even[i] << " " ;
	cout << endl;

	return 0;
}
