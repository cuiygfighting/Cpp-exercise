#include <iostream>
using namespace std;
#include <sort.h>
void sort::display()
{
	cout << "排列好的数据为:"<<" ";
	for (int i = 1; i <= max; i++)
		cout << L->number[i]<<"  ";
	cout << "这种排序法共比较了" << countcompare << "次" << "  共交换了"<<countswap<<"次"<<endl;
}