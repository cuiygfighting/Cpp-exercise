/*题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，
当然我们需要合成后的链表满足单调不减规则*/

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {                                   //非递归版
public:
	ListNode * Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* MergeHead = NULL;
		ListNode* CurrentHead = NULL;
		if (pHead1 == NULL && pHead2 != NULL)
			return pHead2;
		else if (pHead1 != NULL && pHead2 == NULL)
			return pHead1;
		else if (pHead1 == NULL && pHead2 == NULL)
			return NULL;
		while (pHead1 != NULL && pHead2 != NULL)
		{
			if (pHead1->val <= pHead2->val)
			{
				if (MergeHead == NULL) MergeHead = CurrentHead = pHead1;
				else
				{
					CurrentHead->next = pHead1;
					CurrentHead = CurrentHead->next;
				}
				pHead1 = pHead1->next;
			}
			else
			{
				if (MergeHead == NULL) MergeHead = CurrentHead = pHead2;
				else
				{
					CurrentHead->next = pHead2;
					CurrentHead = CurrentHead->next;
				}
				pHead2 = pHead2->next;
			}
		}
		if (pHead1) CurrentHead->next = pHead1;
		else  CurrentHead->next = pHead2;
		return MergeHead;
	}
};

class Solution {                      //递归版
public:
	ListNode * Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* MergeHead = NULL;
		if (pHead1 == NULL) return pHead2;
		if (pHead2 == NULL) return pHead1;
		if (pHead1->val <= pHead2->val)
		{
			MergeHead = pHead1;
			MergeHead->next = Merge(pHead1->next, pHead2);
		}
		else
		{
			MergeHead = pHead2;
			MergeHead->next = Merge(pHead1, pHead2->next);
		}
		return MergeHead;
	}
};