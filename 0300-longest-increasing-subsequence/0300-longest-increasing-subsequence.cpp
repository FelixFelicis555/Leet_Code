class Solution {
public:
    int n;
    vector<int>arr;
    int dp[2502];
    int rec(int level)
    {
        // pruning-step
        if(level<0)
            return 0;
        

        
        
        // cache-check
        if(dp[level]!=-1)
            return dp[level];
        // compute
        
        int ans=1;
        for(int prev_taken=0;prev_taken<level;prev_taken++)
        {
            if(arr[prev_taken]<arr[level])
                ans=max(ans,1+rec(prev_taken));
        }
        return dp[level]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        for(auto x:nums)
            arr.push_back(x);
        memset(dp,-1,sizeof(dp));
        int best=0;
        for(int i=0;i<n;i++)
            best=max(best,rec(i));
        return best;
        
        
    }
};