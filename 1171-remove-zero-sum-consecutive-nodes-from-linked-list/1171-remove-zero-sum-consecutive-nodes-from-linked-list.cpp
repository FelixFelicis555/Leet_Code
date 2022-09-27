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
    void DeleteNodes(int s,ListNode*start,ListNode*end,unordered_map<int,ListNode*>&mp)
    {
        ListNode*cur=start;
        while(cur!=end)
        {
            s+=cur->val;
            mp.erase(s);
            cur=cur->next;
        }    
    }   
    ListNode* removeZeroSumSublists(ListNode* head) {
      unordered_map<int,ListNode*>mp;
        mp[0]=NULL;
        ListNode*cur=head;
        int sum=0;
        while(cur)
        {
            sum+=cur->val;
            if(mp.find(sum)==mp.end())
            {
                mp[sum]=cur;
            } 
            else
            {
                if(sum==0)
                {
                    DeleteNodes(0,head,cur,mp);
                    head=cur->next;
                } 
                else
                {
                    DeleteNodes(sum,mp[sum]->next,cur,mp);
                    mp[sum]->next=cur->next;
                }    
            } 
            cur=cur->next;
                
        }  
        return head;
    }
};