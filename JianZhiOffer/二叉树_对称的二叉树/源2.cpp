/*题目描述
请实现一个函数，用来判断一颗二叉树是不是对称的。
注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。*/

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

//递归版：根节点以及其左右子树，左子树的左子树和右子树的右子树相同。
// 左子树的右子树和右子树的左子树相同即可。
//二叉树是否对称，只要采用前序、中序、后序、层次遍历等任何一种遍历方法，
//分为先左后右和先右后左两种方法，只要两次结果相等就说明这棵树是一颗对称二叉树。
class Solution {             
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (!pRoot) return true;
		return  isSymmetricalHelper(pRoot->left, pRoot->right);
	}

	bool isSymmetricalHelper(TreeNode* left, TreeNode* right)
	{
		if (left == NULL && right == NULL) return true;
		if (left == NULL || right == NULL) return false;
		return
			left->val == right->val&&
			isSymmetricalHelper(left->left, right->right) &&
			isSymmetricalHelper(left->right, right->left);
	}

};

class Solution {             //迭代版：借助两个队列进行层序遍历
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (!pRoot) return true;
		queue<TreeNode*> q1, q2;
		TreeNode* left, *right;
		q1.push(pRoot->left);
		q2.push(pRoot->right);

		while (!q1.empty() && !q2.empty())
		{
			left = q1.front();
			q1.pop();
			right = q2.front();
			q2.pop();
			if (left == NULL && right == NULL) continue;
			if (left == NULL || right == NULL) return false;
			if (left->val != right->val) return false;
			q1.push(left->left);
			q1.push(left->right);
			q2.push(right->right);
			q2.push(right->left);
		}
		return true;
	}
};