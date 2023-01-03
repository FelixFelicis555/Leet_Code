class Solution {
public:
    int dp[501][501];
    bool help(int i,int j,vector<int>&p)
    {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=max(p[i]-help(i+1,j,p),p[j]-help(i,j-1,p));
    }
    bool stoneGame(vector<int>& p) {
       return true;
    }
};