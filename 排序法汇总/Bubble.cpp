#include <sort.h>
void sort::Bubble()
{  
	countswap = 0;
	countcompare = 0;
	for(int i=1;i<L->length;i++)
		for (int j = L->length - 1; j >= i; j--)
		{
			if (L->number[j] > L->number[j + 1])
			{
				swap(j, j + 1);
				countswap++;
			}
			countcompare++;
		}
}

void sort::Bubble_optimize1()
{
	bool statu=true;
	countswap = 0;
	countcompare = 0;
	for (int i = 1; i < L->length&&statu; i++)     //防止已经排好了顺序还继续对i循环
	{
		statu = false;                   
		for (int j = L->length - 1; j >= i; j--)
		{
			if (L->number[j] > L->number[j + 1])
			{
				swap(j, j + 1);
				statu = true;
				countswap++;
			}
			countcompare++;
		}
	}
}

void sort::Bubble_optimize2()
{
	countswap = 0;
	countcompare = 0;
	int lastswap= L->length - 1;
	for (int i = 1; i < L->length;i= ++lastswap)     
	{
		for (int j = L->length - 1; j >= i; j--)               //j比较到上一轮最后一次交换位置的前一个
		{
			if (L->number[j] > L->number[j + 1])
			{
				swap(j, j + 1);
				lastswap = j;
				countswap++;
			}
			countcompare++;
		}
	}
}

/*原始冒泡排序比较次数固定为n*(n-1)/2次，两种优化方法可以减少比较的次数，
但不会减少交换的次数。给定一个数组，三种冒泡排序算法的交换次数都是固定的*/