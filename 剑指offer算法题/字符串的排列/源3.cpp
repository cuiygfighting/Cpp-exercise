/*题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。*/

class Solution {                     //即求字符的全排列，递归法
public:
	vector<string> Permutation(string str) {
		vector<string> target;
		if (str.empty()) return target;
		PermutationHelp(str, target, 0);
		sort(target.begin(), target.end());
		return target;
	}

	void PermutationHelp(string str, vector<string> &target, int begin)
	{
		if (begin == str.size() - 1)
		{
			if (find(target.begin(), target.end(), str) == target.end())
				target.push_back(str);
		}
		else
		{
			for (int i = begin; i<str.size(); ++i)
			{
				swap(str[begin], str[i]);
				PermutationHelp(str, target, begin + 1);
				swap(str[begin], str[i]);
			}
		}
	}

	void swap(char &a, char &b)
	{
		char tmp = a;
		a = b;
		b = tmp;
	}
};