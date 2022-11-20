class Solution {
public:
    int dp[1003][1003];
    int M=1e9+7;
    
    int add(int a, int b)
    {   
        return ((a % M) + (b % M)) % M;
    }
    int ans(int i,int j,int k,int minLength,string &s)
    {
        if(i>s.length()) // You couldn't split the string at a position out of bounds
        {
            return 0;
        }
        
        if(i==s.length()) // If you could have reached the end of the string,then you need to check few other conditions,partiton-count & last-character of string must be non-prime
        {            
            if(j==k-1 && (s.back()!='2'&&s.back()!='3'&&s.back()!='5'&&s.back()!='7'))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        // cache-check
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        
        // For each position,we explore two cases,Don't split on that position,Split on that position if we can(s[i] is prime & s[i-1] is non-prime)
        if((s[i]=='2'||s[i]=='3'||s[i]=='5'||s[i]=='7') && (s[i-1]!='2'&&s[i-1]!='3'&&s[i-1]!='5'&&s[i-1]!='7'))
        {
            return dp[i][j] = add(ans(i+1,j,k,minLength,s),ans(i+minLength,j+1,k,minLength,s));
        // Save & return
        }
        else
        {
            return dp[i][j] = ans(i+1,j,k,minLength,s);
        }
    }
    int beautifulPartitions(string s, int k, int minLength) {
       if(s[0]!='2'&&s[0]!='3'&&s[0]!='5'&&s[0]!='7')
        {
            return 0;
        }
        memset(dp,-1,sizeof(dp));
        return ans(minLength,0,k,minLength,s);
     
    }
};