#include <sort.h>
void sort::Insert()
{
	countswap = 0;
	countcompare = 0;
	int j;
	for (int i = 2; i <= L->length; i++)
	{
		if (L->number[i] < L->number[i - 1])
		{
			L->number[0] = L->number[i];
			j = i;
			countcompare++;
			while (L->number[0] < L->number[j - 1])
			{
				L->number[j] = L->number[j - 1];
				j--;
				countswap++;
				countcompare++;
			}
			L->number[j] = L->number[0];
		}
	}
}