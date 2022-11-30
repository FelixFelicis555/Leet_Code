class Solution {
public:
    string convertToTitle(int columnNumber) {
       string s="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string ans="";
        int n=columnNumber;
        while(n>0)
        {
            n=n-1;
            int k=n%26;
            ans.push_back(s[k]);
            n=n/26;
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};