#include <Sqlist.h>
class sort
{
public:
	void cinnumber();
	void restore();
	//冒泡排序
	void Bubble();
	void Bubble_optimize1();
	void Bubble_optimize2();
	//直接插入排序
	void Insert();
	//选择排序
	void Select();
	//希尔排序
	void Shell();
	//堆排序
	void Heap();
	void HeapAdjust(int s, int m);
	//归并排序
	void MSort(int first, int last);
	void MergeAdjust(int first, int mid, int last);
	void Merge();
	void MergePass(int increment, int last);
	void Merge_optimize();
	//快速排序
	int    QuikPartition(int first, int last);
	int    QuikPartition_optimize1(int first, int last);
	int    QuikPartition_optimize2(int first, int last);
	void QSort(int first, int last);
	void QSort_optimize1(int first, int last);
	void QSort_optimize2(int first, int last);
	void Quik();

	void display();
	void swap( int , int );
private:
	SqVector L;      
	SqVector L0;      //用来保存输入的原始数据，以便在需要时恢复给L
	int countswap=0;      //用于标记数据交换的次数，从而表征排序算法的好坏
	int countcompare = 0;     //用于标记数据比较的次数，从而表征排序算法的好坏
};
