/*题目描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5*/

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/
class Solution {
public:
	ListNode * deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL) return pHead;
		ListNode* NewHead = new ListNode(0);
		NewHead->next = pHead;
		ListNode* pre = NewHead;
		ListNode* cur = pHead;
		while (cur != NULL)
		{
			if (cur->next != NULL && cur->val == cur->next->val)
			{
				while (cur->next != NULL && cur->val == cur->next->val)
					cur = cur->next;
				pre->next = cur->next;
				cur = cur->next;
			}
			else
			{
				pre = pre->next;
				cur = cur->next;
			}
		}
		return NewHead->next;
	}
};