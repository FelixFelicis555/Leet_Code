class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int>m;
        for(char x:p)
            m[x]++;
        int len=INT_MAX;
        int begin=0,end=0;
        vector<int>res;
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
        
                    char startchar=s[begin];
                    if(m.count(startchar)==1)
                    {
                        m[startchar]++;
                        if(m[startchar]>0)
                            counter++;
                    }
                    if(end-begin==p.size())
                    {
                        res.push_back(begin);
                    }    
                    begin++;
                }
            
        }
        return res;
    }
};