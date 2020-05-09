/*题目描述
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。*/

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
	ListNode * EntryNodeOfLoop(ListNode* pHead)
	{
		if (!pHead) return NULL;
		ListNode *fast = pHead, *low = pHead;
		while (fast&&fast->next)
		{
			fast = fast->next->next;
			low = low->next;
			if (fast == low)
				break;
		}

		if (!fast || !fast->next) return NULL;//最少包含两个元素，且不能为无环链表
		low = pHead;  //fast或者low从头开始
		while (fast != low)
		{
			fast = fast->next;
			low = low->next;
		}
		return fast;
	}
};