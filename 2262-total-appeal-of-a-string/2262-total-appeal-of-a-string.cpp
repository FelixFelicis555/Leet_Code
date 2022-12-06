class Solution {
public:
    long long appealSum(string s) {
       long long n=s.size();
        long long ans=0;
        for(int i=0;i<26;i++)
        {
            char ch=(char)('a'+i);
            long long t=0;
            long long c=0;
            for(int j=0;j<n;j++)
            {
                if(s[j]==ch)
                {
                    t+=(c*(c+1)/2);
                    c=0;
                }
                else
                    c++;
            }
            t+=(c*(c+1))/2;
            ans+=(n*(n+1))/2-t;
            
        }
        return ans;
        
    }
};