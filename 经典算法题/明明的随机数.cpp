#include<iostream>
using namespace std;
int main()
{
	int num, tmp;
	while (cin >> num)
	{
		int a[1001] = { 0 };
		while (num--)
		{
			cin >> tmp;
			a[tmp] = 1;
		}
		for (int i = 0; i < 1001; i++)
			if (a[i])   cout << i<<endl;
	}
	return 0;
}