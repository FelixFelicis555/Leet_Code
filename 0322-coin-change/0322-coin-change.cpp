class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      int v=amount;
        int dp[v+1];
        dp[0]=0;
        for(int i=1;i<=v;i++)
            dp[i]=INT_MAX;
        int m=coins.size();
        for(int i=1;i<=v;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(coins[j]<=i)
                {
                    int sum=dp[i-coins[j]];
                    if(sum!=INT_MAX && sum+1<dp[i])
                    {
                        dp[i]=sum+1;
                    }
                }
            }
        }
        if(dp[amount]==INT_MAX)
            return -1;
        return dp[amount];
    }
};