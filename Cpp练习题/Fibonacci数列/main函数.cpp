/*
问题描述：给出一个正整数，求fibonacci数列的第n项
*/

#include <iostream>
using namespace std;
int main()
{
	long recur(int);         //利用递归法
	long array(int);         //利用数组法
	long iteration(int);   //利用迭代法
	long dynamic(int);   //动态规划
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
	cout << "The nth of Fibonacci array is:" << iteration(n) << endl;
	cout << "The nth of Fibonacci array is:" << dynamic(n) << endl;
	return 0;
}
