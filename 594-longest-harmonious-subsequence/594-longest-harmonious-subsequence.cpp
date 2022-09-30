class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans=0;
        map<int,int>mp;
        for(int n:nums)
        {
            if(mp.find(n)==mp.end())
            {
                mp[n]=1;
            } 
            else
            {
                mp[n]++;
            }  
            if(mp.find(n+1)!=mp.end())
            {
                ans=max(ans,mp[n]+mp[n+1]);
            } 
            if(mp.find(n-1)!=mp.end())
            {
                ans=max(ans,mp[n]+mp[n-1]);
            }    
        } 
        return ans;
    }
};