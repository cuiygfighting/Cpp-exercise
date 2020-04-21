#include <iostream>
using namespace std;
int main()
{   
	void convert(int n);
	int n;
	cout << "please input an integer:";
	cin >> n;
	cout << "output: ";
	if (n < 0)
	{
		n = -n;
		cout << "-";
	}
	convert(n);
	cout << endl;
	return 0;
}

void convert(int n)
{
	char c; 
	int i;
	if ((i = n/10) != 0)  convert(i);
	c= n % 10 + '0';
	cout << c ;
}