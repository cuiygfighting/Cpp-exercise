#include <sort.h>
void sort::Select()
{
	int min;
	countswap = 0;
	countcompare = 0;
	for (int i = 1; i < L->length; i++)
	{
		min = i;
		for (int j = i + 1; j <= L->length; j++)
		{
			if (L->number[j] < L->number[min])
				min = j;
			countcompare++;
		}
		if (min != i)
		{
			swap(i, min);
			countswap++;
		}
	}
}