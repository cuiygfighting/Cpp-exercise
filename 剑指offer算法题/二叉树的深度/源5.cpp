/*题目描述
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点
（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。*/

// 递归遍历，仅仅一行
class Solution {
public:
	int TreeDepth(TreeNode* pRoot) {
		return pRoot ? max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1 : 0;
	}
};

//迭代版本
class Solution {
public:
	int TreeDepth(TreeNode* pRoot) {
		if (!pRoot) return 0;
		queue<TreeNode*> que;
		que.push(pRoot); int depth = 0;
		while (!que.empty()) {
			int size = que.size();
			depth++;
			for (int i = 0; i<size; i++) {      //一次处理一层的数据
				TreeNode *node = que.front();
				que.pop();
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
		}
		return depth;
	}
};