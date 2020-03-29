#include <sort.h>
void sort::restore()
{
	for (int i = 1; i <= max; i++)
	{
		L->number[i] = L0->number[i];
	}
}