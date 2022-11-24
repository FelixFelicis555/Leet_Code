class Solution {
public:
    int dp[501][501];
    int solve(string word1,string word2,int i,int j)
    {
        if(i==0 && j==0)
            return 0;
        if(i==0)
            return j;
        if(j==0)
            return i;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(word1[i-1]==word2[j-1])
            return dp[i][j]=solve(word1,word2,i-1,j-1);
        int x= min(min(solve(word1,word2,i,j-1),solve(word1,word2,i-1,j)),solve(word1,word2,i-1,j-1))+1;
        return dp[i][j]=x;
    }
    int minDistance(string word1, string word2) {
      int n=word1.size();
        int m=word2.size();
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,n,m);
    }
};