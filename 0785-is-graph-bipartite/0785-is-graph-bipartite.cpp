class Solution {
public:
    int v[100001];
    int col[100001];
    bool dfs(int i,int c,vector<vector<int>>&graph)
    {
        v[i]=1;
        col[i]=c;
        for(int u:graph[i])
        {
            if(!v[u])
            {
                if(dfs(u,c^1,graph)==false)
                    return false;
            }
            else if(col[u]==col[i])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        for(int i=0;i<n;i++)
        {
            v[i]=0;
            col[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            if(!v[i])
            {
                if(!dfs(i,0,graph))
                    return false;
            }
        }
        return true;
    }
};