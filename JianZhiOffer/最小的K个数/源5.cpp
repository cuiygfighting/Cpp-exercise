/*题目描述
输入n个整数，找出其中最小的K个数。
例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,*/

class Solution {                //利用快排进行全排序，时间复杂度O（nlogn）
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> tmp;
		if (input.empty() || k>input.size()) return tmp;
		sort(input.begin(), input.end());
		for (int i = 0; i<k; i++)
			tmp.push_back(input[i]);
		return tmp;
	}
};

class Solution {           //用最大堆保存这k个数，每次只和堆顶比，如果比堆顶小，删除堆顶，新数入堆。 
public:                         //时间复杂度O（nlogk）
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		int len = input.size();
		if (len <= 0 || k>len || k <= 0) return vector<int>();
		vector<int> res(input.begin(), input.begin() + k);
		//建堆
		make_heap(res.begin(), res.end());

		for (int i = k; i<len; i++)
		{
			if (input[i]<res[0])
			{
				res[0] = input[i];
				make_heap(res.begin(), res.end());
			}
		}
		//使其从小到大输出
		sort_heap(res.begin(), res.end());

		return res;
	}
};