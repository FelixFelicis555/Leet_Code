class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int res=0;
        int start=0;
        for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i])!=m.end())
            {
                res=max(res,i-start);
                start=max(start,1+m[s[i]]);
            } 
            m[s[i]]=i;
        }  
        return max(res,(int)s.size()-start);
    }
};