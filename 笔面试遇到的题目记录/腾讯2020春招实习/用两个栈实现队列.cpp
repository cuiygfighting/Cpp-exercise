#include<iostream>
#include<stack>
using namespace std;
#include<string>
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	void poll() {
		int temp;
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				temp = stack1.top();
				stack2.push(temp);
				stack1.pop();
			}
		}
		stack2.pop();
	}

	int peek() {
		int temp;
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				temp = stack1.top();
				stack2.push(temp);
				stack1.pop();
			}
		}
		temp = stack2.top();
		return temp;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main()
{
	string str;
	int number;
	Solution que;
	while (cin >> str )
	{
		if (str == "add")
		{
			cin >> number;
			que.push(number);
		}
		else if (str == "poll") que.poll();
		else if (str == "peek")
		{
			int tmp = que.peek();
			cout << tmp<<endl;
		}
	}
	return 0;
}