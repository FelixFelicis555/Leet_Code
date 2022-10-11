class Solution {
public:
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int minimumEffortPath(vector<vector<int>>& heights) {
      int n=heights.size();
        int m=heights[0].size();
      int dist[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dist[i][j]=INT_MAX;
            }
        }
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty())
        {
            int currd=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if(x==n-1 && y==m-1)
                return currd;
            for(int i=0;i<4;i++)
            {
              int  new_x=x+dx[i];
              int  new_y=y+dy[i];
                if(new_x>=0 && new_y>=0 && new_x<n && new_y<m)
                {
                int newd=max(currd,abs(heights[new_x][new_y]-heights[x][y]));
                   if(newd<dist[new_x][new_y])
                   {
                       dist[new_x][new_y]=newd;
                       pq.push({newd,{new_x,new_y}});
                   }
                }
            }
        }
        return 0;
    }
};