/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(-1);
        ListNode* h=head;
        int sum=0;
        bool flag=false;
        while(l1!=NULL||l2!=NULL)
        {
            sum=0;
            if(l1!=NULL)
            {sum+=l1->val;
            l1=l1->next;
            }
            if(l2!=NULL)
            {sum+=l2->val;
            l2=l2->next;}
            if(flag)
            sum++;
            h->next=new ListNode(sum%10);
            h=h->next; 
            flag=sum>=10?true:false;
        }
        if(flag)
        {
            h->next=new ListNode(1);
        }
           return head->next;
    }
};