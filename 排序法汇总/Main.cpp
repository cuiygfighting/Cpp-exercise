#include <iostream>
#include <iomanip>
#include <sort.h>
using namespace std;
int main()
{
	sort sort1;
	sort1.cinnumber();

	sort1.Insert();
	sort1.display();
	sort1.restore();
	
	sort1.Bubble();
	sort1.display();
	sort1.restore();

	sort1.Bubble_optimize1();
	sort1.display();
	sort1.restore();

	sort1.Bubble_optimize2();
	sort1.display();
	sort1.restore();
	
	sort1.Select();
	sort1.display();
	sort1.restore();

	system("pause");
	return 0;
}