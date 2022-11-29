class Solution {
public:
    unordered_map<string,vector<string>>adj;
    void dfs(unordered_set<string>&vis,string s,vector<string>&v)
    {
        if(vis.find(s)!=vis.end())
            return;
        vis.insert(s);
        v.push_back(s);
        for(int i=0;i<adj[s].size();i++)
            dfs(vis,adj[s][i],v);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,string>m;
        unordered_set<string>vis;
        vector<vector<string>>ans;
        for(int i=0;i<accounts.size();i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                adj[accounts[i][1]].push_back(accounts[i][j]);
                adj[accounts[i][j]].push_back(accounts[i][1]);
                m[accounts[i][j]]=accounts[i][0];
                
            }
        }
        for(int i=0;i<accounts.size();i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(vis.find(accounts[i][j])==vis.end())
                {
                    vector<string>v;
                    dfs(vis,accounts[i][j],v);
                    sort(v.begin(),v.end());
                    v.insert(v.begin(),m[accounts[i][j]]);
                    ans.push_back(v);
                }
            }
        }
        return ans;
            
    }
};