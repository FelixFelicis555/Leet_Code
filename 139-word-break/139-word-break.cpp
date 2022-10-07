class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      int n=s.length();
      unordered_set<string>dict;
        for(auto x:wordDict)
            dict.insert(x);
        vector<bool>dp(n+1,false);
        dp[n]=true;
        for(int i=n-1;i>=0;i--)
        {
            string word="";
            for(int j=i;j<n;j++)
            {
               word+=s[j];
                if(dict.find(word)!=dict.end())
                {
                    if(dp[j+1])
                        dp[i]=true;
                }    
            }    
        } 
        return dp[0];
    }
};