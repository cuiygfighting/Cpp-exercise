#include <Sqlist.h>
void swap(SqVector L,int i,int j)
{
	double temp = L->number[i];
	L->number[i] = L->number[j];
	L->number[j] = temp;
}