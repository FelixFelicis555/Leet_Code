class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>>g(n);
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start});
        vector<bool>seen(n);
        for(int i=0;i<edges.size();i++)
        {
            const int u=edges[i][0];
            const int v=edges[i][1];
            const double prob=succProb[i];
            g[u].push_back({v,prob});
            g[v].push_back({u,prob});
            
        }
        while(!pq.empty())
        {
            auto [prob,u]=pq.top();
            pq.pop();
            if(u==end)
                return prob;
            if(seen[u])
                continue;
            seen[u]=true;
            for(const auto [x,p]:g[u])
            {
                if(seen[x])
                    continue;
                pq.push({prob*p,x});
            }
        }
        return 0;
    }
};