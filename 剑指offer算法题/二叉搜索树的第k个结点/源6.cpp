/*题目描述
给定一棵二叉搜索树，请找出其中的第k小的结点。例如， 
（5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4*/

/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
*/

//思路：二叉搜索树按照中序遍历的顺序打印出来正好就是排序好的顺序。
//     所以，按照中序遍历顺序找到第k个结点就是结果。
class Solution {
public:
	TreeNode * KthNode(TreeNode* pRoot, int k)
	{
		if (!pRoot || k<1) return nullptr;
		vector<TreeNode*> vec;
		KthNodeHelper(pRoot, vec);
		if (k>vec.size()) return nullptr;
		return vec[k - 1];
	}

	void KthNodeHelper(TreeNode* p, vector<TreeNode*> &vec)
	{
		if (p == NULL) return;
		KthNodeHelper(p->left, vec);
		vec.push_back(p);
		KthNodeHelper(p->right, vec);
	}
};

//来一点精简的代码
class Solution {
	int count = 0;
public:
	TreeNode * KthNode(TreeNode* pRoot, unsigned int k)
	{
		if (pRoot) {
			TreeNode *ret = KthNode(pRoot->left, k);
			if (ret) return ret;   //只有该节点为要找的节点时，ret才不为null，并将目标节点逐层返回
			if (++count == k) return pRoot;
			ret = KthNode(pRoot->right, k);
			if (ret) return ret;
		}
		return nullptr;
	}
};