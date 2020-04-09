/*题目描述
在一个字符串(0<=字符串长度<=10000，全部由字母组成)
中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）*/

//核心还是hash，利用每个字母的ASCII码作hash来作为数组的index
class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		map<char, int> res;
		for (int i = 0; i<str.size(); i++) res[str[i]]++;
		for (int i = 0; i<str.size(); i++)
		{
			if (res[str[i]] == 1)
				return i;
		}
		return -1;
	}
};

class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		int* res = new int[58];
		for (int i = 0; i<str.size(); i++)
			res[str[i] - 65]++;
		for (int i = 0; i<str.size(); i++)
		{
			if (res[str[i] - 65] == 1)
				return i;
		}
		return -1;
	}
};