#include <Sqlist.h>
class sort
{
public:
	void cinnumber();
	void restore();
	void Bubble();
	void Bubble_optimize1();
	void Bubble_optimize2();
	void Insert();
	void Select();
	void display();
	void swap( int , int );
private:
	SqVector L;      
	SqVector L0;      //用来保存输入的原始数据，以便在需要时恢复给L
	int countswap=0;      //用于标记数据交换的次数，从而表征排序算法的好坏
	int countcompare = 0;     //用于标记数据比较的次数，从而表征排序算法的好坏
};
