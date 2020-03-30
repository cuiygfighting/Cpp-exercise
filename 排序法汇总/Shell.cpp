#include <sort.h>
void sort::Shell()
{
	countswap = 0;
	countcompare = 0;
	int increment = L->length,i,j;
	do
	{
		increment = increment / 3 + 1;                //增量序列最后一个值必须是1
		for ( i = increment + 1; i <= L->length; i++)
		{
			if (L->number[i] < L->number[i - increment])
			{
				countcompare++;
				L->number[0] = L->number[i];
				for (j = i - increment; j > 0 && L->number[j] > L->number[0]; j -= increment)
				{
					L->number[j + increment] = L->number[j];
					countcompare++;
					countswap++;
				}
				L->number[j + increment] = L->number[0];
			}
		}
	} 
	while (increment>1);
}