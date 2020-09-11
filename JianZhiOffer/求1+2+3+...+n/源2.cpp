/*题目描述
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等
关键字及条件判断语句（A?B:C）*/

class Solution {
public:
	int Sum_Solution(int n) {
		char sum[n][n + 1];
		return sizeof(sum) >> 1;
	}
};

class Solution {                      //利用逻辑与的短路特性实现递归终止
public:
	int Sum_Solution(int n) {
		int sum = n;
		n && (sum += Sum_Solution(n - 1));
		return sum;
	}
};

/*不用加减乘除做加法*/
/*题目描述
写一个函数，求两个整数之和，
要求在函数体内不得使用+、-、*、/四则运算符号。*/
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