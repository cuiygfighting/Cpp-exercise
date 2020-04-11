/*题目描述
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，
就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，
请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,
要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！*/

class Solution {             //利用substr方法先补后切
public:
	string LeftRotateString(string str, int n) {
		int length = str.length();
		if (length == 0) return "";
		//n = n % str.length();
		str += str;
		return str.substr(n, length);
	}
};


// 按照剑指offer书上的方法，两次翻转字符串。
class Solution {
public:
	string LeftRotateString(string str, int n) {
		reverse(str.begin(), str.end());
		reverse(str.begin(), str.begin() + str.size() - n);
		reverse(str.begin() + str.size() - n, str.end());
		return str;
	}
};


//这道题考的核心是应聘者是不是可以灵活利用字符串翻转。假设字符串abcdef，n = 3，
//设X = abc，Y = def，所以字符串可以表示成XY，如题干，问如何求得YX。
//假设X的翻转为XT，XT = cba，同理YT = fed，那么YX = (XTYT)T，三次翻转后可得结果。
class Solution {
public:
	string LeftRotateString(string str, int n)
	{
		int len = str.size();
		if (len == 0) return str;
		n %= len;
		for (int i = 0, j = n - 1; i < j; ++i, --j) swap(str[i], str[j]);
		for (int i = n, j = len - 1; i < j; ++i, --j) swap(str[i], str[j]);
		for (int i = 0, j = len - 1; i < j; ++i, --j) swap(str[i], str[j]);
		return str;
	}
};
