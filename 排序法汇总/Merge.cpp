#include <sort.h>
void sort::MergeAdjust(int first, int mid, int last)
{
	SqVector temp = new Sqlist;
	int i = first, j = mid + 1;
	int k=0;
	while (i <= mid && j <= last)
	{
		if (L->number[i] < L->number[j])
			temp->number[k++] = L->number[i++];
		else
			temp->number[k++] = L->number[j++];
	}
	while (i <= mid)
		temp->number[k++] = L->number[i++];
	while (j <= last)
		temp->number[k++] = L->number[j++];
	for (i = 0; i < k; i++)
		L->number[first + i] = temp->number[i];   //合并完后将临时数组中排好序的部分写回原数组
}

void sort::MSort(int first,int last)
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		MSort(first, mid);          //递归使左边有序
		MSort(mid + 1, last);   //递归使右边有序
		MergeAdjust(first, mid, last);  //将两个有序序列合并
	}
}

void sort::Merge()
{
	MSort(1, L->length);  //为了使Merge函数形参不出现L->length,需要重新封装一个函数
}


/*归并排序大量引用了递归，尽管代码上比较清晰容易理解，但这会造成时间和空间上的浪费。
以下优化方法可以将递归转换为迭代，直接从头开始，使性能进一步提高*/
void sort::MergePass(int increment,int last)
{
	int i = 1;
	while (i <= last - 2 * increment + 1)
	{
		MergeAdjust(i, i + increment - 1, i + 2*increment - 1);
		i += 2 * increment;
	}
	if (i < last - increment + 1)
		MergeAdjust(i, i + increment - 1, last);
}

void sort::Merge_optimize()
{
	for (int i = 1; i <= L->length; i *= 2)
	{
		MergePass(i, L->length);
	}
}