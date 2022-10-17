class Solution {
public:
    int numDecodings(string s) {
        int dp[102];
        memset(dp,0,sizeof(dp));
        int n=s.size();
        dp[n+1]=1;
        dp[n]=1;
        for(int i=n-1;i>=0;i--)
        {
            int op1=s[i]-'0',op2=0;
            if(i<s.size()-1)
            {
                op2=op1*10+s[i+1]-'0';
            }
            if(op1>0)
                dp[i]+=dp[i+1];
            if(op1>0 && op2>0 &&op2<=26)
                dp[i]+=dp[i+2];
        }
        return dp[0];
    }
};