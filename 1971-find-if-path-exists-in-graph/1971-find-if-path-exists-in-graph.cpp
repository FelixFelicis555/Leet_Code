class Solution {
public:
   
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)    {
        vector<int>al[n];
       for(auto &e:edges)
       {
           al[e[0]].push_back(e[1]);
           al[e[1]].push_back(e[0]);
       }
        int s=source,d=destination;
        if(s==d)
            return true;
        vector<int>vis(n,0);
        queue<int>q;
        vis[s]=true;
        q.push(s);
        while(!q.empty())
        {
            int k=q.front();
            q.pop();
            for(auto x : al[k])
            {
                if(x==d)
                    return true;
                if(!vis[x])
                {
                    vis[x]=1;
                    q.push(x);
                }
            }
        }
        return false;
    }
};