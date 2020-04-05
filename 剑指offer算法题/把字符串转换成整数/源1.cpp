/*题目描述
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 
数值为0或者字符串不是一个合法的数值则返回0*/

//此题的关键在于处理好数值溢出，int能表示的范围为:-2147483648-2147483648.
class Solution {
public:
	int StrToInt(string str) {
		int size = str.size();
		int  value = 0;
		int flag;
		int i = 0;
		int overvalue = 0;
		if (size == 0) return 0;
		if (str[0] == '+') flag = 1, i = 1;
		else if (str[0] == '-') flag = -1, i = 1;
		else flag = 1;
		for (; i<size; ++i)
		{
			if (!('0' <= str[i] && str[i] <= '9')) return 0;
			if (flag>0)
				if ((value>INT_MAX / 10) || (value == INT_MAX / 10 && str[i] - '0'>7))
					return 0;
			if (flag<0)
				if ((value>INT_MAX / 10) || (value == INT_MAX / 10 && str[i] - '0'>8))
					return 0;
			value = 10 * value + str[i] - '0';
		}
		value = value * flag;
		return value;
	}
};