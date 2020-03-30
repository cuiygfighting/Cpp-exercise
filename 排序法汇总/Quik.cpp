#include<sort.h>
int    sort::QuikPartition(int first, int last)      //承担排序和返回枢轴值的任务
{
	double pivotkey = L->number[first];
	while (first < last)
	{
		while (first < last&&L->number[last]>=pivotkey) last--;
		swap(first, last);
		while (first < last&&L->number[first] <=pivotkey) first++;
		swap(first, last);
	}
	return first;
}

void sort::QSort(int first, int last)
{
	int pivot;
	if (first < last)
	{
		pivot = QuikPartition(first, last);
		QSort(first, pivot-1);
		QSort(pivot+1, last);
	}
}

void sort::Quik()
{
	QSort(1, L->length);
}


/*优化选取枢轴
pivotkey = L->number[first]是一个潜在的性能瓶颈，其越接近子序列的中间，子序列就越快成为成为有序序列。
可以采用三数取中法，将三个数的中间值作为枢轴，避免枢轴取到子序列中的极值。*/
int    sort::QuikPartition_optimize1(int first, int last)      //承担排序和返回枢轴值的任务
{
	double pivotkey;
	int mid = first + (last - first) / 2;
	if (L->number[first]>L->number[mid])  swap(first, mid);           //保证左端较小
	if (L->number[mid] > L->number[last])   swap(mid, last);       //保证中间较小
	if (L->number[first] < L->number[mid])     swap(first, mid);   //保证左端为中间值
	pivotkey = L->number[first];
	while (first < last)
	{
		while (first < last&&L->number[last] >= pivotkey) last--;
		swap(first, last);
		while (first < last&&L->number[first] <= pivotkey) first++;
		swap(first, last);
	}
	return first;
}

/*优化不必要的交换
用替代方式而不是交换，这样可以减少多次交换数据的操作，从而提升性能*/
int    sort::QuikPartition_optimize2(int first, int last)      //承担排序和返回枢轴值的任务
{
	double pivotkey;
	int mid = first + (last - first) / 2;
	if (L->number[first]>L->number[mid])  swap(first, mid);           //保证左端较小
	if (L->number[mid] > L->number[last])   swap(mid, last);       //保证中间较小
	if (L->number[first] < L->number[mid])     swap(first, mid);   //保证左端为中间值
	pivotkey = L->number[first];
	L->number[0] = pivotkey;
	while (first < last)
	{
		while (first < last&&L->number[last] >= pivotkey) last--;
		L->number[first] = L->number[last];
		while (first < last&&L->number[first] <= pivotkey) first++;
		L->number[last] = L->number[first];
	}
	L->number[first] = L->number[0];
	return first;
}

/*优化小数组的排序方案
*/
void sort::QSort_optimize1(int first, int last)
{
	int pivot;
	if ((last - first) > 7)             //当数组太小时，可以直接用插入排序
	{
		pivot = QuikPartition(first, last);
		QSort_optimize1(first, pivot - 1);
		QSort_optimize1(pivot + 1, last);
	}
	else
		Insert();
}

/*优化递归操作
利用迭代而不是递归的方法可以缩减堆栈深度，降低空间复杂度，从而提升整体性能
*/
void sort::QSort_optimize2(int first, int last)
{
	int pivot;
	if ((last - first) > 7)             //当数组太小时，可以直接用插入排序
	{
		while (first < last)
		{
			pivot = QuikPartition(first, last);
			QSort_optimize2(first, pivot - 1);
			first = pivot + 1;
		}
	}
	else
		Insert();
}