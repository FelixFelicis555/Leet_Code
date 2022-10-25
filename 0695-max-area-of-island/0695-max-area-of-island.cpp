class Solution {
public:
    bool isValid(int i,int j,int n,int m)
    {
        if(i<0 || j<0 || i>=n || j>=m)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void dfs(int&area,vector<vector<int>>&grid,int i,int j,int n,int m)
    {
        if(!isValid(i,j,n,m))
            return;
        if(grid[i][j]==0)
        {
            return;
        }
        area++;
        grid[i][j]=0;
        dfs(area,grid,i+1,j,n,m);
        dfs(area,grid,i-1,j,n,m);
        dfs(area,grid,i,j-1,n,m);
        dfs(area,grid,i,j+1,n,m);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int maxarea=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                int area=0;
                dfs(area,grid,i,j,n,m);
                maxarea=max(area,maxarea);
                }
                
                
            }
        }
        return maxarea;
    }
};