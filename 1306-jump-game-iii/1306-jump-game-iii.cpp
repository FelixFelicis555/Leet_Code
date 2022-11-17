class Solution {
public:
    vector<int>adj[50005];
    bool canReach(vector<int>& arr, int start) {
     int n=arr.size();
        if(arr[start]==0)
            return true;
        bool vis[n];
        for(int i=0;i<n;i++)
        {
            adj[i].push_back(i+arr[i]);
            adj[i].push_back(i-arr[i]);
            vis[i]=false;
        }
        queue<int>q;
        q.push(start);
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            if(arr[cur]==0)
                return true;
            if(cur+arr[cur]<n && !vis[cur+arr[cur]])
                                      {
                                          q.push(cur+arr[cur]);
                                          vis[cur+arr[cur]]=true;
                                      }
            if(cur-arr[cur]>=0 && !vis[cur-arr[cur]])
            {
                q.push(cur-arr[cur]);
                vis[cur-arr[cur]]=true;
            }
        }
        return false;
    }
};