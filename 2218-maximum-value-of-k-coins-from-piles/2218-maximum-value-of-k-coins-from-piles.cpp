class Solution {
public:
    long long dp[1002][2002];
    int l;
    int n;
    long long solve(vector<vector<int>>& piles, int p, int c){
        if(c==l)
            return 0;
        if(p==n)
            return 0;
        
        if(dp[p][c]!=-1)
            return dp[p][c];
        
        
        long long sum=0, ans=0;
        ans=max(ans, solve(piles,p+1,c));
        
        int sz=piles[p].size();
        int lim=min(l-c, sz);
        
        for(int i=0;i<lim;i++){
            sum=piles[p][i];
            ans=max(ans, sum+solve(piles,p+1,c+(i+1)));
        }
        return dp[p][c]=ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n=piles.size();
        memset(dp,-1,sizeof(dp));
        l=k;
        for(int i=0;i<piles.size();i++)
        {
            int sz=piles[i].size();
            for(int j=1;j<sz;j++)
                piles[i][j]+=piles[i][j-1];
        }
        return solve(piles,0,0);
        
    }
};