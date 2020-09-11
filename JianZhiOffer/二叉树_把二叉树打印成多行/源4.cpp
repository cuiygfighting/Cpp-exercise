/*题目描述
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。*/

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

//思路：二叉树层序遍历升级版，把每层单独放在一个矢量里。借助队列可轻松实现
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> > res;
		if (!pRoot) return res;
		queue<TreeNode*> que;
		que.push(pRoot);
		TreeNode* cur = NULL;
		while (!que.empty())
		{
			vector<int> tmp;
			int size = que.size();
			for (int i = 0; i<size; i++)
			{
				cur = que.front();
				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
				tmp.push_back(cur->val);
				que.pop();
			}
			if (!tmp.empty())
				res.push_back(tmp);
		}
		return res;
	}

};