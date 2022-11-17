class Solution {
public:
    int dp[100005][2][3];
    int mod=1e9+7;
    int n1;
    long long solve(int i,int a,int l)
    {
        if(a>1 || l>2)
            return 0;
        if(i==n1)
            return 1;
        if(dp[i][a][l]!=-1)
            return dp[i][a][l];
        long long ans=0;
        ans=(ans%mod +solve(i+1,a,0)%mod+solve(i+1,a,l+1)%mod + solve(i+1,a+1,0)%mod)%mod;
        return dp[i][a][l]=ans;
    }
    int checkRecord(int n) {
      n1=n;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0);  
    }
};