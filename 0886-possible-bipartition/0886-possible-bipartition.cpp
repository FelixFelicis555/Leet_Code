class Solution {
public:
    bool dfs(int i,vector<int>&vis,vector<int>&color,int c,vector<vector<int>>&g)
    {
        vis[i]=1;
        color[i]=c;
        for(int u:g[i])
        {
            if(color[i]==color[u])
                return false;
            if(!vis[u] && dfs(u,vis,color,c^1,g)==false)
                return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>color(n+1,-1);
        vector<int>vis(n+1,0);
        vector<vector<int>>g(n+1);
        bool ans=true;
        int c=1;
        for(vector<int>v:dislikes)
        {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        for(int i=1;i<n+1;i++)
        {
            if(vis[i]==0)
                ans=ans && dfs(i,vis,color,c,g);
        }
        return ans;
    }
};