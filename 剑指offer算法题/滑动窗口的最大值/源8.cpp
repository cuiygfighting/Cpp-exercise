/*题目描述
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。*/


/*思路:
用一个双端队列，队列第一个位置保存当前窗口的最大值，当窗口滑动一次
1.判断当前最大值是否过期
2.新增加的值从队尾开始比较，把所有比他小的值丢掉
*/
class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> res;
		if (size<1) return res;
		deque<int> deq;
		for (int i = 0; i<num.size(); i++)
		{
			while (!deq.empty() && num[deq.back()] <= num[i])
				deq.pop_back();
			if (!deq.empty() && i - deq.front() + 1>size)
				deq.pop_front();
			deq.push_back(i);
			if (i + 1 >= size)
				res.push_back(num[deq.front()]);
		}
		return res;
	}
};