class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        int mini=INT_MAX;
        priority_queue<int>pq;
        for(auto &x:nums)
        {
            if(x%2!=0)
            {
                x*=2;
            }
            maxi=max(maxi,x);
            mini=min(mini,x);
        }
        if(maxi==mini)
            return 0;
        int diff=maxi-mini;
        for(auto x:nums)
            pq.push(x);
        while((pq.top())%2==0)
        {
            int cur=pq.top();
            diff=min(diff,cur-mini);
            pq.pop();
            cur/=2;
            mini=min(mini,cur);
            pq.push(cur);
            
        }   
        diff=min(diff,pq.top()-mini);
        return diff;
        
    }
};