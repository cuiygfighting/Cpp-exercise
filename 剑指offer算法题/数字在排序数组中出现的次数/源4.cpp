/*题目描述
统计一个数字在排序数组中出现的次数*/
class Solution {
public:
	int bisearch(vector<int> data, double k)
	{
		int low = 0, high = data.size() - 1, mid;
		while (low <= high)
		{
			mid = low + (high - low) / 2;
			if (data[mid]>k) high = mid - 1;
			else if (data[mid]<k) low = mid + 1;
		}
		return low;
	}
	int GetNumberOfK(vector<int> data, int k) {
		return bisearch(data, k + 0.5) - bisearch(data, k - 0.5);
	}
};