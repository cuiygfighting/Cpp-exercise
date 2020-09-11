/*题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树*/

//从下往上遍历，如果子树是平衡二叉树，则返回子树的高度；
//如果发现子树不是平衡二叉树，则直接停止遍历，这样至多只对每个结点访问一次

class Solution {
public:
	bool IsBalanced(TreeNode* p, int &dep)
	{
		if (p == NULL) return true;
		int left = 0, right = 0;
		if (IsBalanced(p->left, left) && IsBalanced(p->right, right))
		{
			int dif = left - right;
			if (dif>1 || dif<-1) return false;
			dep = (left>right ? left : right) + 1;
			return true;
		}
		return false;
	}

	bool IsBalanced_Solution(TreeNode* pRoot) {
		int dep = 0;
		return IsBalanced(pRoot, dep);
	}
};