class Solution {
public:
    vector<int>adj[2001];
    int c[2001];
    bool solve(int x)
    {
        if(c[x]==1)
            return true;
        if(c[x]==0)
        {
            c[x]=1;
            for(auto&u:adj[x])
            {
                if(solve(u))
                    return true;
            }
        }
        c[x]=2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        for(auto&x:prerequisites)
        {
            adj[x[1]].push_back(x[0]);
        }
        for(int i=0;i<n;i++)
            c[i]=0;
        for(int i=0;i<n;i++)
        {
            if(solve(i))
                return false;
        }
        return true;
    }
};