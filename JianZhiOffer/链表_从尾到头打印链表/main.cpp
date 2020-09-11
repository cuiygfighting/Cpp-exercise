/*题目描述
输入一个链表，按链表从尾到头的顺序返回一个ArrayList。*/

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

class PrintListFromTailtoHead         //递归法，尾插
{
public:
	vector<int> res;
	vector<int> printListFromTailToHead(ListNode* head) {
		if (head != NULL)
		{
			if (head->next != NULL) printListFromTailToHead(head->next);
			res.push_back(head->val);
		}
		return res;
	}
}；

class PrintListFromTailtoHead         //递归法，头插
{
public:
	vector<int> printListFromTailToHead(ListNode* head)
	{
		vector<int> array;
		if (head != NULL)
		{
			array.insert(array.begin(), head->val);
				if (head->next != NULL)
				{
					vector<int> temp;
					temp = printListFromTailToHead(head->next);
					array.insert(array.begin(), temp.begin(), temp.end());
				}
		}
		return array;
	}
};


class PrintListFromTailtoHead         //迭代法，头插
{
public:
	vector<int> printListFromTailToHead(ListNode* head)
	{
		vector<int>  value;
		if (head != NULL)
		{
			value.insert(value.begin(),head->val);
			while (head->next != NULL)
			{
				value.insert(value.begin(), head->next->val);
				head = head->next;
			}
		}
		return value;
	}

}；