#include <iostream>
using namespace std;
#include <sort.h>
void sort::cinnumber()
{
	L = new Sqlist;
	L0 = new Sqlist;
	cout << "Please input your numbers:";
	for (int i = 1; i <= max; i++)
	{
		cin >> L0->number[i];
		L->number[i] = L0->number[i];
	}
	L->length = max;
	L0->length = max;
}
