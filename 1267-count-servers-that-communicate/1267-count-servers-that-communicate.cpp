class Solution {
public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};
    int c=0;
    bool isValid(int i,int j,int n,int m,vector<vector<int>>&grid)
    {
        if(i>=n || j>=m ||i<0 || j<0)
            return false;
        return true;
    }
    void dfs(int i,int j,int n,int m,vector<vector<int>>&grid,int&cc)
    {
        grid[i][j]=0;
        cc++;
        for(int a=0;a<4;a++)
        {
            int x=i+dx[a];
            int y=j+dy[a];
            while(isValid(x,y,n,m,grid))
            {
                if(grid[x][y]==1)
                    dfs(x,y,n,m,grid,cc);
                x+=dx[a];
                y+=dy[a];
            }
        }
        return ;
    }
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                   int cc=0;
                    dfs(i,j,n,m,grid,cc);
                    if(cc>1)
                        c+=cc;
                }
            }
        }
        return c;
    }
};