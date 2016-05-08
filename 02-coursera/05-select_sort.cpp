#include <iostream>
using namespace std;

int main()
{
	int i = 0, j = 0, i_max = 0;
	int data[10];
	int tmp = 0;

	cout << "input 10 numbers:" << endl;
	for(i = 0; i < 10; i++)
		cin >> data[i];

	for(i = 0; i < 10-1; i++)
	{
		i_max = i;
		for(j = i + 1; j < 10; j++)
			if(data[j] > data[i_max]) i_max = j;
		
		if(i_max != i)
		{
			tmp = data[i];
			data[i] = data[i_max];
			data[i_max] = tmp;
		}
	}	
	
	for(i = 0; i < 10; i++)
		cout << data[i] << " ";

	cout << endl;

	return 0;
}
