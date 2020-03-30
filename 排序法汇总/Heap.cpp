#include <sort.h>
void sort::HeapAdjust(int s, int m)   //已知L->number[s->m]中除了L->number[s]外其余结点都满足大顶堆定义
{	                                                       //该函数用于调整L->number[s],使L->number[s->m]成为大顶堆
	double temp = L->number[s];     
	for (int j = 2 * s; j <= m; j*=2)
	{
		if (j<m&&L->number[j] < L->number[j + 1])  { countcompare ++; j++; }
		if (temp >= L->number[j])  { countcompare ++; break; }
		L->number[s] = L->number[j]; 
		s = j;
	}
	L->number[s] = temp; 
}

void sort::Heap()
{
	countswap = 0;
	countcompare = 0;
	int i;
	for (i = L->length / 2; i >=1; i--)   //初始化堆
		HeapAdjust(i, L->length);
	for (i = L->length;i>1; i--)
	{
		swap(1, i);
		countswap++;
		HeapAdjust(1, i - 1);
	}
}