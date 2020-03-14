long  recur(int n)
{
	long f;
	if (n == 1 || n == 2) f = 1;
	else f = recur(n - 2) + recur(n - 1);
	return f;
}