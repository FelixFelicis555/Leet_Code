class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>m;
        for(char x:t)
            m[x]++;
        int len=INT_MAX;
        int begin=0,end=0;
        int counter=m.size();
        string ans="";
        while(end<s.size())
        {
            char endchar=s[end];
            if(m.find(endchar)!=m.end())
            {
                m[endchar]--;
                if(m[endchar]==0)
                    counter--;
            }
            end++;
                
                while(counter==0)
                {
                    if(end-begin<len)
                    {
                        len=end-begin;
                        ans=s.substr(begin,end-begin);
                    }
                    char startchar=s[begin];
                    if(m.count(startchar)==1)
                    {
                        m[startchar]++;
                        if(m[startchar]>0)
                            counter++;
                    }
                    begin++;
                }
            
        }
        return ans;
    }
};