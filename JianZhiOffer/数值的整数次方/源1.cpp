/*题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

保证base和exponent不同时为0*/

class Solution {                                                                 //递归法
public:
	double power(double base, int n)
	{
		if (n == 1) return base;
		if (n % 2 == 0) return (power(base, n / 2))*(power(base, n / 2));
		else  return  (power(base, (n - 1) / 2))*(power(base, (n - 1) / 2))*base;
	}
	double Power(double base, int exponent) {
		if (base == 0)
		{
			if (exponent >= 0) return 0;
			//else throw invalid_argument("Invalid input!");
		}
		//else if(base<0) throw invalid_argument("Invalid input!");
		else
		{
			if (exponent == 0) return 1;
			else
				return (exponent>0) ? power(base, exponent) : 1 / power(base, -exponent);
		}

	}
};

class Solution {
public:
	double Power(double base, int exponent) {
		double value = 1;
		int n = exponent;
		if (exponent == 0) return 1;
		else if (exponent<0) n = -exponent;
		while (n != 0)
		{
			if ((n & 1) == 1) value *= base;
			base *= base;
			n = n >> 1;
		}
		return exponent>0 ? value : (1 / value);
	}
};