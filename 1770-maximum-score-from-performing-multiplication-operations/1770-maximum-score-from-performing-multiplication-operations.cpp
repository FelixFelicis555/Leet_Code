class Solution {
public:
    int n,m;
    int dp[1005][1005];
    int solve(int l,vector<int>&nums,int ind,vector<int>&multipliers)
    {
       if(ind==m)
           return 0;
        if(dp[l][ind]!=INT_MIN)
            return dp[l][ind];
        int ans=0;
        ans=max(nums[l]*multipliers[ind]+solve(l+1,nums,ind+1,multipliers),nums[n-(ind-l)-1]*multipliers[ind]+solve(l,nums,ind+1,multipliers));
        return dp[l][ind]=ans;
    }    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
      n=nums.size();
        m=multipliers.size();
        for(int i=0;i<1005;i++)
        {
            for(int j=0;j<1005;j++)
                dp[i][j]=INT_MIN;
        }
        return solve(0,nums,0,multipliers);
    }
};