class Solution {
public:
     int n;
    int dp[301][11];
    int solve(int i,int d,vector<int>&jd)
    {
        // Base-cases
        if(i==n && d==0)
            return 0;
        // Pruning-step
        if(i==n || d==0)
            return 1e7;
        // cache-check
        if(dp[i][d]!=-1)
        {
            return dp[i][d];
        }
        int cur=jd[i];
        int ans=jd[i]+solve(i+1,d-1,jd);
        
        // Compute-step
        for(int j=i+1;j<n;j++)
        {
            cur=max(cur,jd[j]);
            ans=min(ans,solve(j+1,d-1,jd)+cur);
        }
       
        // Save and return
        return dp[i][d]=ans;
        
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        vector<int>jd(jobDifficulty);
        n=jd.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,d,jd);
        return ans>=1e7?-1:ans;
    }
};