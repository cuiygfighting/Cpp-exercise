long array(int n)
{
	long a[30] = {1,1 };
	for (int i = 2; i < 30; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	return a[n-1];
}