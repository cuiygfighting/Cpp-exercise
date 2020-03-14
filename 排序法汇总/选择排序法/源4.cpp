#include <iostream>
using namespace std;
int main()
{
	void sort_select(float [], int n);
	float a[10];
	cout << "*****sort_select*****" << endl;
	cout << "Please input the array:";
	for (int i = 0; i < 10; i++) cin >> a[i];
	sort_select(a, 10);
	cout << "The sorted array:" << endl;
	for (int i = 0; i < 10; i++)  cout << a[i] << " ";
	cout << endl;
	return 0;
}

/*
*******选择排序法*******
原理：找出后面最小的一项，和最前面的一项交换
*/
void sort_select(float a[], int n)
{
	float flag;
	int k;
	for (int i = 0; i < n - 1; i++)
	{   
		k = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[k])
			{
				k = j;
			}
		flag = a[i];
		a[i] = a[k];
		a[k] = flag;
	}
}