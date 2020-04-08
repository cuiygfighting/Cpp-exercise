/*题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。*/

/*
struct TreeNode {                  //递归版
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	void convert(TreeNode* p, TreeNode* &pre)
	{
		if (!p) return;
		convert(p->left, pre);
		p->left = pre;
		if (pre) pre->right = p;
		pre = p;
		convert(p->right, pre);
	}
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (!pRootOfTree) return nullptr;
		TreeNode* pre = nullptr;
		convert(pRootOfTree, pre);
		TreeNode* target = pRootOfTree;
		while (target->left)
			target = target->left;
		return target;
	}
};

class Solution {                   //非递归版本
public:
	TreeNode * Convert(TreeNode* pRootOfTree)
	{
		if (!pRootOfTree) return nullptr;
		TreeNode* pre = nullptr;
		TreeNode* p = pRootOfTree;
		vector< TreeNode*> stack;
		while (p != NULL || !stack.empty())
		{
			while (p)
			{
				stack.push_back(p);
				p = p->left;
			}
			p = stack.back();
			stack.pop_back();
			if (pre == nullptr)
			{
				pRootOfTree = p; pre = p;
			}
			else
			{
				p->left = pre;
				pre->right = p;
				pre = p;
			}
			p = p->right;
		}
		return pRootOfTree;
	}
};