1.不能对cin >> a这种进行表达式，如不能if(cin >> a == 0)
2.cin >> a >> b; >>从流中读取数据时会自动跳过输入流中的空格，Tab键，换行符和空白字符
  cin>>无法读取空格，可以用getchar,cin.get来读取空格
  可以直接cin>>string，但不能读取其中的空格
3.若题目中没有提及整数的范围，直接用long或者long long

/*输入描述:
输入包括两个正整数a,b(1 <= a, b <= 10^9),输入数据包括多组。*/
#include <iostream>
using namespace std;
int main()
{
	int a, b;
	while (cin >> a >> b)
		cout << a + b << endl;
	return 0;
}


/*
输入描述:
输入第一行包括一个数据组数t(1 <= t <= 100)
接下来每行包括两个正整数a,b(1 <= a, b <= 10^9)*/
#include <iostream>
using namespace std;
int main()
{
	int num, a, b;
	cin >> num;
	for (int i = 0; i<num; i++)
	{
		cin >> a >> b;
		cout << a + b << endl;
	}
	return 0;
}


/*
输入描述:
输入数据包括多组。
每组数据一行,每行的第一个整数为整数的个数n(1 <= n <= 100), n为0的时候结束输入。
接下来n个正整数,即需要求和的每个正整数。*/
#include<iostream>
using namespace std;
int main()
{
	int num, temp;
	while (cin >> num)
	{
		if (num == 0) break;
		else
		{
			int sum = 0;
			for (int i = 0; i<num; i++)
			{
				cin >> temp;
				sum += temp;
			}
			cout << sum << endl;
		}
	}
	return 0;
}



/*输入描述 :
输入数据有多组, 每行表示一组输入数据。

每行不定有n个整数，空格隔开。(1 <= n <= 100)。
示例1
输入
1 2 3
4 5
0 0 0 0 0
输出
6
9
0*/
#include<iostream>
using namespace std;
int main()
{
	int tmp, sum = 0;
	while (cin >> tmp)
	{
		sum += tmp;
		if (cin.get() == '\n')   //会从输入流中读取掉换行符，使cin从下一行开始读
		{
			cout << sum << endl;
			sum = 0;
		}
	}
	return 0;
}