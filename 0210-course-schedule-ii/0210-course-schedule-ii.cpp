class Solution {
public:
    vector<int>adj[2001];
    int in[2001];
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int>q;
        for(auto&x:prerequisites)
        {
            adj[x[1]].push_back(x[0]);
            in[x[0]]++;
        }
        vector<int>ans;
        int n=numCourses;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
          q.push(i);
        }
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            ans.push_back(cur);
            for(auto&u:adj[cur])
            {
                in[u]--;
                if(in[u]==0)
                {
                    q.push(u);
                }
            }
            
        }
        if(ans.size()==n)
            return ans;
        else
            return {};
    }
};