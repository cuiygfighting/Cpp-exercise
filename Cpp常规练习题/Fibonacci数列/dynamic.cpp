long dynamic(int n)
{
	long fn1 = 0, fn2 = 1;
	while(n--)
	{
		fn2 += fn1;
		fn1 = fn2 - fn1;
	}
	return fn1;
}