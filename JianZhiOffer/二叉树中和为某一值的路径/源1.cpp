/*题目描述
输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
(注意: 在返回值的list中，数组长度大的数组靠前)*/

/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {                              //考察点为二叉树的深度优先遍历
	vector<vector<int>> res;
	vector<int> tmp;
public:
	void dfs(TreeNode* root, int e)
	{
		tmp.push_back(root->val);
		if (root->val == e && !root->left && !root->right)
			res.push_back(tmp);
		else
		{
			if (root->left) dfs(root->left, e - root->val);
			if (root->right) dfs(root->right, e - root->val);
		}
		tmp.pop_back();
	}
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (root) dfs(root, expectNumber);
		return res;
	}
};