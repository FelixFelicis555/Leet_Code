class Solution {
public:
    string simplifyPath(string path) {
       path+="/";
        int n=path.size();
        vector<string>dirs;
        string cur="";
        for(int i=0;i<n;i++)
        {
            char c=path[i];
            if(c=='/')
            {
                if(!cur.empty())
                {
                    if(cur=="..")
                    {
                        if(!dirs.empty())
                            dirs.pop_back();
                    }
                    else if(cur!=".")
                        dirs.push_back(cur);
        
                        cur="";
                }
            }
            else
            {
                cur+=c;
            }
        }
        if(!cur.empty())
            dirs.push_back(cur);
        string ans;
        for(auto &s:dirs)
            ans+="/"+s;
        return ans.empty()?"/":ans;
    }
};