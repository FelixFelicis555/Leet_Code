class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        
        // base-case
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
           dp[i]=0; 
           for(int j=1;j<=i;j++)
               dp[i]=dp[i]+(1LL *dp[i-j]*dp[j-1]);
        }
        return dp[n];
    }
};