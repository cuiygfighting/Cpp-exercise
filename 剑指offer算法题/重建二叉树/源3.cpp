/*题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。*/

/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (vin.size() == 0) return nullptr;
		vector<int> pre_left, pre_right, vin_left, vin_right;
		TreeNode* root = new  TreeNode(pre[0]);
		int mid = 0;
		for (int i = 0; i<vin.size(); i++)
		{
			if (pre[0] == vin[i])
			{
				mid = i;
				break;
			}
		}
		for (int i = 0; i<mid; i++)
		{
			vin_left.push_back(vin[i]);
			pre_left.push_back(pre[i + 1]);
		}
		for (int i = mid + 1; i<vin.size(); i++)
		{
			vin_right.push_back(vin[i]);
			pre_right.push_back(pre[i]);
		}
		root->left = reConstructBinaryTree(pre_left, vin_left);
		root->right = reConstructBinaryTree(pre_right, vin_right);
		return root;
	}
};

/*思路：
由先序序列第一个pre[0]在中序序列中找到根节点位置gen
以gen为中心遍历
0~gen左子树
子中序序列：0~gen - 1，放入vin_left[]
子先序序列：1~gen放入pre_left[]， + 1可以看图，因为头部有根节点
gen + 1~vinlen为右子树
子中序序列：gen + 1 ~vinlen - 1放入vin_right[]
子先序序列：gen + 1 ~vinlen - 1放入pre_right[]
由先序序列pre[0]创建根节点
连接左子树，按照左子树子序列递归（pre_left[]和vin_left[]）
连接右子树，按照右子树子序列递归（pre_right[]和vin_right[]）
返回根节点*/