/*题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。
队列中的元素为int类型。*/

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
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
		stack2.pop();
		return temp;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

/*<分析>：
入队：将元素进栈A
出队：判断栈B是否为空，如果为空，则将栈A中所有元素pop，并push进栈B，栈B出栈；如果不为空，栈B直接出栈。
栈A用来存储元素，栈B只是作为一个中介
