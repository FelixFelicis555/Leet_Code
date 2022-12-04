class Solution {
public:
    vector<vector<int>>adj;
    int ds[501];
    int find(int i)
    {
        return ds[i]<0?i:ds[i]=find(ds[i]);
    }
    
    int partition(int start)
    {
        vector<int> group(adj.size(), -1);
        vector<int> q{start};
       int cnt = 0;
      group[start] = 0;
     while(!q.empty()) {
        ++cnt;
        vector<int> q1;
        for (int i : q) {
            for (int j : adj[i]) {
                if (group[j] == -1) {
                    group[j] = cnt;
                    q1.push_back(j);
                }
                else if (abs(group[i] - group[j]) != 1) {
                    return -1;
                }
            }
        }
        swap(q, q1);
    }
    return cnt;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        adj=vector<vector<int>>(n+1,vector<int>());
        fill_n(begin(ds),n+1,-1);
        
        for(auto &e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            int i=find(e[0]),j=find(e[1]);
            if(i!=j)
                ds[j]=i;
        }
        vector<vector<int>>groups(n+1);
        for(int i=1;i<=n;i++)
        {
            groups[find(i)].push_back(i);
        }
        int res=0;
        for(int i=1;i<=n;i++)
        {
            if(groups[i].size()==0)
                continue;
            if(groups[i].size()==1)
                ++res;
            else
            {
                int res1=-1;
            for(int j:groups[i])
            {
                res1=max(res1,partition(j));
            }
                if(res1==-1)
                    return -1;
                res+=res1;
            }
        }
        return res;
    }
};