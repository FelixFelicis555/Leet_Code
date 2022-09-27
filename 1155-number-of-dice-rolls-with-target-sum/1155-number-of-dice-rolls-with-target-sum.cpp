class Solution {
public:
    const int m=1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                for(int t=j;t<=target;t++)
                {
                    dp[i][t]=(dp[i][t]+dp[i-1][t-j])%m;
                }    
            }    
        } 
        return dp[n][target];
    }
};