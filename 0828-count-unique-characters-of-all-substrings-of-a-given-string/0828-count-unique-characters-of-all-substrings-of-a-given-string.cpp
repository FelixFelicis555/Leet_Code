class Solution {
public:
    const int m=1000000007;
    int uniqueLetterString(string s) {
        int n=s.size();
        vector<int>l(n);
        vector<int>r(n);
        vector<int>lastL(26,-1);
        vector<int>lastR(26,n);
        for(int i=0;i<n;i++)
        {
           l[i]=i-lastL[s[i]-'A'];
            lastL[s[i]-'A']=i;
        }
        for(int i=n-1;i>=0;i--)
        {
            r[i]=lastR[s[i]-'A']-i;
            lastR[s[i]-'A']=i;
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            count=(count+(l[i]*r[i])%m)%m;
        }
        return count;
    }
};