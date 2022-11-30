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
    ListNode* deleteDuplicates(ListNode* head) {
         ListNode*cur=head;
        ListNode*prev=head;
    
        while(cur!=NULL)
        {
            if(cur->val!=prev->val)
            {
                prev->next=cur;
                prev=cur;
            }
            else
                cur=cur->next;
        }
       if(prev!=cur)
           prev->next=NULL;
        return head;
    }
};