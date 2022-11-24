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
    ListNode *detectCycle(ListNode *head) {
       ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL)
            
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                ListNode*slow1=head;
                while(slow!=slow1)
                {
                    slow=slow->next;
                    slow1=slow1->next;
                }
                return slow;
            }
        
        }
        return NULL;
    }
};