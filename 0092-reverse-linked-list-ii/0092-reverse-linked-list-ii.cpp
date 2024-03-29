/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       int m=left,n=right;
        if(head==NULL)
           return NULL;
        int c=1;
        ListNode*prev=NULL;
        ListNode*t=head;
        while(c<m)
        {
            prev=t;
            t=t->next;
            c++;
        }
        ListNode*c1=t;
        ListNode*p1=prev;
        ListNode*t1=NULL;
        int v=n-m+1;
        while(v>0)
        {
            t1=t->next;
            t->next=prev;
            prev=t;
            t=t1;
            v--;
        }
        if(p1!=NULL)
            p1->next=prev;
        else
            head=prev;
        c1->next=t;
        return head;
        
    }
};