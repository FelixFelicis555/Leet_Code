class Solution {
public:
    vector<string>result;
    void create(string s,unordered_map<string,int>&m,vector<string> ans,int last,int index)
    {
        if(index==s.size())
        {
            string curr;
            for(int i=0;i<ans.size();i++)
            {
                if(i==ans.size()-1)
                curr+=ans[i];
                else
                curr+=ans[i]+' ';
            }
            result.push_back(curr);
            return;
        }
        for(int i=index;i<s.size();i++)
        {
            string temp=s.substr(last,i-last+1);
            if(m[temp])
            {
                ans.push_back(temp);
                create(s,m,ans,i+1,i+1);
                ans.pop_back();
                
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
         unordered_map<string,int>m;
        for(auto w: wordDict)
        m[w]++;
        vector<string> ans;
        create(s,m,ans,0,0);
        return result;
    }
};