/*题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同*/

class Solution {
	bool judge(vector<int>& sequence, int left, int right)
	{
		if (left >= right) return true;   //用>是为了防止右之树为空
		int temp = left;
		while (sequence[temp]<sequence[right] && temp<right) temp++;
		int mid = temp;
		while (sequence[temp]>sequence[right] && temp<right) temp++;
		if (temp<right) return false;
		return judge(sequence, left, mid - 1) && judge(sequence, mid, right - 1);

	}
public:

	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() == 0) return false;
		return judge(sequence, 0, sequence.size() - 1);
	}
};

/*
思路：
BST的后序序列的合法序列是，对于一个序列S，最后一个元素是x （也就是根），
如果去掉最后一个元素的序列为T，那么T满足：T可以分成两段，前一段（左子树）小于x，
后一段（右子树）大于x，且这两段（子树）都是合法的后序序列。完美的递归定义 : ) 。*/