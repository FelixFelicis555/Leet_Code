class Solution {
public:
     int n;
    vector<int> dx={0,0,1,-1};
    vector<int>dy={1,-1,0,0};
    bool is_valid(int x,int y)
    {
        return (x>=0 && x<n && y>=0 && y<n);
    }
    int dist(pair<int,int>&a,pair<int,int>&b)
    {
        return abs(a.first-b.first)+abs(a.second-b.second) -1;
    } 
    void flood_fill(set<pair<int,int>>&A,vector<vector<int>>&grid,int x,int y)
    {
      A.insert({x,y});
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(is_valid(nx,ny) && grid[nx][ny] && !A.count({nx,ny}))
                flood_fill(A,grid,nx,ny);
        }    
    }    
    int shortestBridge(vector<vector<int>>& grid) {
         n=grid.size();
        set<pair<int,int>>a,b;
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                    continue;
                
                if(a.empty())
                {
                    flood_fill(a,grid,i,j);
                } 
                else if(b.empty() && !a.count({i,j}))
                    flood_fill(b,grid,i,j);
            }    
        } 
        int ans=2*n;
        for(auto i: a)
        {
            for(auto j:b)
                ans=min(ans,dist(i,j));
        }  
        return ans;
    }   
};