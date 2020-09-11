/*题目描述
请实现两个函数，分别用来序列化和反序列化二叉树
二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，
从而使得内存中建立起来的二叉树可以持久保存。序列化可以基于先序、中序、后序、层序的
二叉树遍历方式来进行修改，序列化的结果是一个字符串，序列化时通过 某种符号表示空节点（#）
，以 ！ 表示一个结点值的结束（value!）。
二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。*/

/*
1. 对于序列化：使用前序遍历，递归的将二叉树的值转化为字符，并且在每次二叉树的结点
不为空时，在转化val所得的字符之后添加一个' ， '作为分割。对于空节点则以 '#' 代替。
2. 对于反序列化：按照前序顺序，递归的使用字符串中的字符创建一个二叉树(特别注意：
在递归时，递归函数的参数一定要是char ** ，这样才能保证每次递归后指向字符串的指针会
随着递归的进行而移动！！！)
*/

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
class Solution {
public:
	char* Serialize(TreeNode *root) {
		if (root == NULL) return NULL;
		string str;
		Serialize(root, str);
		char* res = new char[str.length()];
		int i = 0;
		for (i = 0; i<str.length(); i++)
		{
			res[i] = str[i];
		}
		res[i] = '\0';
		return res;
	}
	void Serialize(TreeNode *root, string &str)
	{
		if (root == NULL)
		{
			str += '#';
			return;
		}
		string r = to_string(root->val);
		str += r;
		str += ',';
		Serialize(root->left, str);
		Serialize(root->right, str);
	}

	TreeNode* Deserialize(char *str) {
		if (str == NULL) return NULL;
		TreeNode* res = Deserialize(&str);
		return res;
	}
	TreeNode* Deserialize(char **str)
	{
		if (**str == '#')
		{
			(*str)++; return NULL;
		}
		int num = 0;
		while (**str != ','&&**str != '\0')
		{
			num = 10 * num + (**str - '0');
			(*str)++;
		}
		TreeNode* cur = new TreeNode(num);
		if (**str == '\0')
			return cur;
		else
			(*str)++;
		cur->left = Deserialize(str);
		cur->right = Deserialize(str);
		return cur;
	}
};