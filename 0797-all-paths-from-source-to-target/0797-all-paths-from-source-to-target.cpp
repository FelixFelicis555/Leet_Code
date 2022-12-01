class Solution {
public:
    vector<vector<int>>t;
    void dfs(vector<vector<int>>&graph,vector<int> p,int v)
    {
        p.push_back(v);
        if(v==graph.size()-1)
        {
            t.push_back(p);
            
        }
        for(int u:graph[v])
            dfs(graph,p,u);
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>p;
        dfs(graph,p,0);
        return t;
    }
};