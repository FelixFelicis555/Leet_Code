class Solution {
public:
    int n,m;
    string a,b;
    int dp[1001][1001];
    int rec(int i,int j)
    {
        // return LCS of a[i..n-1] and b[j..m-1]
        
        // base-case
        if(i>=n || j>=m)
            return 0;
        
        // cache-check
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        // compute
        int ans=0;
        ans=max(ans,rec(i+1,j)); // discarding ith char
        ans=max(ans,rec(i,j+1));  // discarding jth char
        if(a[i]==b[j])
        {
            ans=max(ans,1+rec(i+1,j+1)); // matched-case
        }
        
        // save & return
        return dp[i][j]=ans;
        
        
    }
    int longestCommonSubsequence(string text1, string text2) {
      n=text1.size();
      m=text2.size();
        a=text1;
        b=text2;
        memset(dp,-1,sizeof(dp));
        return rec(0,0);
    }
};