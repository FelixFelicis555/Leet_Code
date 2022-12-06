class Solution {
public:
    int longestPalindrome(string s) {
        int count=0;
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            if(m.find(ch)!=m.end())
            {
                count+=2;
                m.erase(ch);
            }
            else
                m[ch]=1;
        }
        if(m.size()>0)
        {
            count++;
        }
        return count;
    }
};