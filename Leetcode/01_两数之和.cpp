//暴力求解法
class Solution {       
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		for (int i = 0; i<nums.size(); i++)
			for (int j = i + 1; j<nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
					return { i,j };
			}
		return {};
	}
};
时间复杂度：O(n ^ 2)
对于每个元素，我们试图通过遍历数组的其余部分来寻找它所对应的目标元素，
这将耗费 O(n)的时间。因此时间复杂度为 O(n ^ 2)。
空间复杂度：O(1)


//两遍哈希表
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> tmp;
		for (int i = 0; i<nums.size(); i++)
			tmp[nums[i]] = i;
		for (int i = 0; i<nums.size(); i++)
		{
			if (tmp.find(target - nums[i]) != tmp.end() && tmp[target - nums[i]] != i)
				return { i,tmp[target - nums[i]] };
		}
		return {};
	}
};
通过以空间换取速度的方式，我们可以将查找时间从 O(n) 降低到 O(1)。
哈希表正是为此目的而构建的，它支持以 近似 恒定的时间进行快速查找。
我用“近似”来描述，是因为一旦出现冲突，查找用时可能会退化到 O(n)。
但只要你仔细地挑选哈希函数，在哈希表中进行查找的用时应当被摊销为 O(1)。
一个简单的实现使用了两次迭代。在第一次迭代中，我们将每个元素的值和它的索引添加到表中。
然后，在第二次迭代中，我们将检查每个元素所对应的目标元素（target - nums[i]）
是否存在于表中。注意，该目标元素不能是 nums[i]本身！
时间复杂度：O(n)，
我们只遍历了包含有 n 个元素的列表一次。在表中进行的每次查找只花费 O(1)O的时间。
空间复杂度：O(n)，
所需的额外空间取决于哈希表中存储的元素数量，该表最多需要存储 n 个元素


//一遍哈希
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> tmp;
		for (int i = 0; i<nums.size(); i++)
		{
			if (tmp.find(target - nums[i]) != tmp.end())
				return { tmp[target - nums[i]],i };
			//tmp[target-nums[i]]为已经加入map的元素的索引，所以小于本轮循环中的i，放在前面
			else tmp[nums[i]] = i;
		}
		return {};
	}
};
在进行迭代并将元素插入到表中的同时，我们还会回过头来检查表中是否已经存在
当前元素所对应的目标元素。如果它存在，那我们已经找到了对应解，并立即将其返回。