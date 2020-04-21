long iteration(int n)
{
	long Temp,fn1=0,fn2=1;
	if (n == 0 || n == 1) return n;
	for (int i = 2; i <= n; i++)
	{
		Temp = fn1 + fn2;
		fn1 = fn2;
		fn2 = Temp;
	}
	return Temp;
}