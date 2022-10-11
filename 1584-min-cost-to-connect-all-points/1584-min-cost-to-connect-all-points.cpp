class Solution {
public:
    int p[1001];
    vector<vector<pair<int,int>>>adj;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        for(int i=0;i<n;i++)
        {
            vector<pair<int,int>>t;
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                int d=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                t.push_back({d,j});
            }
            adj.push_back(t);
        }
        vector<int>vis(n,0);
        vector<int>dist(n,INT_MAX);
        int cost=0;
        pq.push({0,0});
        dist[0]=0;
        while(!pq.empty())
        {
            auto cur=pq.top();
            pq.pop();
            if(vis[cur.second])
                continue;
            vis[cur.second]=1;
            for(auto u:adj[cur.second])
            {
                int dis=u.first;
                int node=u.second;
                if(!vis[node] && dis<dist[node])
                {
                    dist[node]=dis;
                    pq.push({dis,node});
                }
            }
        }
        for(int i=0;i<n;i++)
            cost+=dist[i];
        return cost;
    }
};