class Solution {
public:
    bool isIsomorphic(string s, string t) {
        bool flag=true;
        int n=s.size();
        unordered_map<char,char>m1;
        unordered_map<char,char>m2;
        for(int i=0;i<n;i++)
        {
            if(m1.count(s[i]))
            {
                char ch=m1[s[i]];
                if(t[i]!=ch)
                {
                    flag=false;
                    break;
                }
            }
            else
            {
                if(m2.count(t[i]))
                {
                    flag=false;
                    break;
                }
                m1[s[i]]=t[i];
                m2[t[i]]=s[i];
            }
        }
        return flag;
    }
};