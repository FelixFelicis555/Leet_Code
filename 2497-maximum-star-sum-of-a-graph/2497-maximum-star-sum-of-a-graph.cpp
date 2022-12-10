class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int res=INT_MIN;
        vector<vector<int>>adj(vals.size());
        int n=vals.size();
        for(auto &e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(int i=0;i<n;i++)
        {
            sort(begin(adj[i]),end(adj[i]),[&](int a,int b){
                return vals[a] >vals[b];
            });
            int res1=vals[i];
            for(int j=0;j<k && j<adj[i].size() && vals[adj[i][j]]>0;j++)
            {
                res1+=vals[adj[i][j]];
            }
            res=max(res,res1);
        }
        return res;
    }
};