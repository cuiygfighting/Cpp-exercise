/*
题目描述 
对输入的字符串进行排序后输出
输入描述:
输入有两行，第一行n
第二行是n个空格隔开的字符串
输出描述:
输出一行排序后的字符串，空格隔开，无结尾空格*/
#include<iostream>
using namespace std;
#include<algorithm>
int main()
{
	int n;
	cin >> n;
	vector<string> res;
	string tmp;
	for (int i = 0; i<n; i++)
	{
		cin >> tmp;
		res.push_back(tmp);
	}
	sort(res.begin(), res.end());
	for (auto x : res) cout << x << " ";
	return 0;
}


/*
输入描述:
多个测试用例，每个测试用例一行。

每行通过空格隔开，有n个字符，n＜100
输出描述:
对于每组测试用例，输出一行排序过的字符串，每个字符串通过空格隔开*/
#include<iostream>
using namespace std;
#include<algorithm>
int main()
{
	string tmp;
	vector<string> res;
	while (cin >> tmp)             //输入结束后会自动跳出循环
	{
		res.push_back(tmp);
		if (cin.get() == '\n')
		{
			sort(res.begin(), res.end());
			for (auto x : res) cout << x << " ";
			cout << endl;
			res.clear();
		}
	}
	return 0;
}


/*
题目描述 
对输入的字符串进行排序后输出
输入描述:
多个测试用例，每个测试用例一行。
每行通过,隔开，有n个字符，n＜100
输出描述:
对于每组用例输出一行排序后的字符串，用','隔开，无结尾空格
示例1
输入
a,c,bb
f,dddd
nowcoder
输出
a,bb,c
dddd,f
nowcoder*/
#include<iostream>
using namespace std;
#include<algorithm>
#include <sstream>
int main()
{
	string tmp;
	while (getline(cin, tmp))
	{
		stringstream ss;
		ss << tmp;
		string tmp2;
		vector<string> res;
		while (getline(ss, tmp2, ','))
			res.push_back(tmp2);
		sort(res.begin(), res.end());
		for (int i = 0; i < res.size() - 1; i++)
			cout << res[i] << ',';
		cout << res[res.size() - 1] << endl;
	}
	return 0;
}