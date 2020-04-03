/*题目描述
输入一个链表，反转链表后，输出新链表的表头*/
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {                              ////第一种方法是：非递归方法
public:
	ListNode * ReverseList(ListNode* pHead) {
		if (pHead == nullptr) return nullptr;
		ListNode* pcurrent = pHead;
		ListNode* pPre = nullptr;
		ListNode* pNext = nullptr;
		while (pcurrent)
		{
			pNext = pcurrent->next;
			pcurrent->next = pPre;
			if (!pNext) return pcurrent;
			pPre = pcurrent;
			pcurrent = pNext;
		}
	}
};

class Solution {                                ////第二种方法是：递归方法
public:
	ListNode * ReverseList(ListNode* pHead) {
		if (pHead == NULL || pHead->next == NULL) return pHead;
		ListNode* ReversePhead = ReverseList(pHead->next);
		pHead->next->next = pHead;
		pHead->next = NULL;
		return ReversePhead;
	}
};