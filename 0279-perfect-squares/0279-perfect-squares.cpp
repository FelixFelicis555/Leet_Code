class Solution {
public:
    int help(int n,vector<int>&dp)
    {
      if(n==0)
          return 0;
        int ans=INT_MAX;
        if(dp[n]!=-1)
            return dp[n];
        for(int i=1;i*i<=n;i++)
        {
            int op=1+help(n-i*i,dp);
            ans=min(ans,op);
        }
        return dp[n]=ans;
        
    }
    int numSquares(int n) {
       vector<int>dp(10001,-1);
        return help(n,dp); 
    }
};