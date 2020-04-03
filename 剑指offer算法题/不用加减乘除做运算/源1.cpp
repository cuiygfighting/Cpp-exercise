/*题目描述
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。*/

class Solution {
public:
	int Add(int num1, int num2)
	{
		while (num2 != 0)
		{
			int temp = num1 ^ num2;
			num2 = (num1&num2) << 1;
			num1 = temp;
		}
		return num1;
	}
};

/*两个数异或：相当于每一位相加，而不考虑进位；
两个数相与，并左移一位：相当于求得进位；
将上述两步的结果相加*/

class Solution {
public:
	int Add(int num1, int num2)
	{
		int n1, n2;
		n1 = (num1&num2) << 1;
		n2 = num1 ^ num2;
		while (n1&n2)
		{
			num1 = n1; num2 = n2;
			n1 = (num1&num2) << 1;
			n2 = num1 ^ num2;
		}
		return n1 | n2;

	}
};