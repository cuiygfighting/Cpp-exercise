#include <iostream>
using namespace std;
int main()
{
	void sort_bubble(float a[],int n);
	float a[10];
	cout << "*****sort_bubble*****" << endl;
	cout << "Please input the array:";
	for (int i = 0; i < 10; i++) cin >> a[i];
	sort_bubble(a, 10);
	cout << "The sorted array:" << endl;
	for (int i = 0; i < 10; i++)  cout << a[i]<<" ";
	cout << endl;
	return 0;
}

/*
*******冒泡排序法*******
原理：两两比较交换位置，使大的上升，小的沉底
*/
void sort_bubble(float a[],int n)
{
	float flag;
	for (int i = 0; i < n-1; i++)
		for (int  j = 0; j < n - i-1; j++)
		{
			if (a[j+1]<a[j])
			{
				flag = a[j];
				a[j] = a[j + 1];
				a[j+1] = flag;
			}
		}
}