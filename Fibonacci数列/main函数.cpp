/*
问题描述：给出一个正整数，求fibonacci数列的第n项
*/

#include <iostream>
using namespace std;
int main()
{
	long recur(int);   //外部利用递归的函数原型声明
	long array(int);   //外部利用数组的函数原型声明
	int n;
	cout << "Please inout the number:";
	cin >> n;
	if (n <= 0)
	{
		cout << "Error! fault input!" << endl << "Please input a positive number:" << endl;
		cin >> n;
	}
	cout << "The nth of Fibonacci array is:" << recur(n)<<endl;
	cout << "The nth of Fibonacci array is:" << array(n) << endl;
	return 0;
}
