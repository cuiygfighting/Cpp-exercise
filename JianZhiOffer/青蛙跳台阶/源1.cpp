/*题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）*/

class Solution {                           //斐波那契迭代法。
public:
	int jumpFloor(int number) {
		int result, fn1 = 1, fn2 = 2;
		if (number == 1) result = 1;
		else if (number == 2) result = 2;
		for (int i = 3; i <= number; i++)
		{
			result = fn1 + fn2;
			fn1 = fn2;
			fn2 = result;
		}
		return result;
	}
};

/*题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法*/

class Solution {
public:
	int jumpFloorII(int number) {                //分析容易得知f(n)=2*f(n-1),n>=2
		int target = 1;
		if (number<1) return -1;
		if (number == 1) return 1;
		for (int i = 2; i <= number; i++)
			target *= 2;
		return target;
	}
};