/*题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，
一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。（注意，输出结果中请
不要返回参数中的节点引用，否则判题程序会直接返回空）*/

/*
struct RandomListNode {
int label;
struct RandomListNode *next, *random;
RandomListNode(int x) :
label(x), next(NULL), random(NULL) {
}
};
*/
class Solution {
public:
	RandomListNode * Clone(RandomListNode* pHead)
	{
		if (!pHead) return nullptr;
		RandomListNode* tmp;
		RandomListNode* current = pHead;
		while (current)
		{
			tmp = new RandomListNode(current->label);
			tmp->next = current->next;
			current->next = tmp;
			current = tmp->next;
		}
		current = pHead;
		while (current)
		{
			tmp = current->next;
			if (current->random) tmp->random = current->random->next;
			current = tmp->next;
		}
		RandomListNode* res = pHead->next;
		current = pHead;
		while (current->next)
		{
			tmp = current->next;
			current->next = tmp->next;
			current = tmp;
		}
		return res;
	}
};