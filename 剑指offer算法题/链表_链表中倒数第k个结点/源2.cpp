/*题目描述
输入一个链表，输出该链表中倒数第k个结点*/

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
	ListNode * FindKthToTail(ListNode* pListHead, unsigned int k) {
		unsigned int count = 0;
		ListNode* p = pListHead;                          //遍历2次
		while (p != NULL)
		{
			count++;
			p = p->next;
		}
		unsigned int value = count - k + 1;
		if (count<k) return nullptr;
		p = pListHead;
		for (unsigned int i = 2; i <= value; i++)
		{
			p = p->next;
		}
		return p;
	}
};

class Solution {
public:
	ListNode * FindKthToTail(ListNode* pListHead, unsigned int k) {
		unsigned int count = 0;
		ListNode* p = pListHead;                           //遍历1次
		ListNode* value = pListHead;
		for (int i = 0; i != k; i++)
		{
			if (!p) return nullptr;
			else
				p = p->next;
		}
		while (p)
		{
			p = p->next;
			value = value->next;
		}
		return value;
	}
};