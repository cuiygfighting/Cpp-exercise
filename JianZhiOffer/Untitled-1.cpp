#include <iostream>
#include <cstdio>
using namespace std;
#include<vector>
#include<string>
int main()
{
	int n;
	cin >> n;
	cin.get();
	string tmp;
	vector<vector<string>> s;
	for (int i = 0; i<n; i++)
	{
		while (cin >> tmp)
		{
			s[i].push_back(tmp);
			if (cin.get() == '\n') break;
		}
	}
	cout << s[0][0];
	return 0;
}