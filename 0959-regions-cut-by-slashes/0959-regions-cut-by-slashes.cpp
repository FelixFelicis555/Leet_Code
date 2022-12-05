class Solution {
public:
    vector<string>g;
    vector<vector<vector<bool>>>vis;
    bool inside(int row,int col)
    {
        int height=g.size();
        int width=g[0].size();
       return 0<=row && row<height && 0<=col && col<width ;
        
    }
    void dfs(int row,int col,int type)
    {
        if(!inside(row,col) || vis[row][col][type])
            return;
        vis[row][col][type]=true;
        if(type==1)
        {
            dfs(row,col+1,3); // on the right
            
       }
        else if(type==0)
            dfs(row-1,col,2);// above me
        else if(type==2)
            dfs(row+1,col,0);// below me
        else if(type==3)
            dfs(row,col-1,1); // on the lef
            else
                assert(false);
        if(g[row][col]!='/')
            dfs(row,col,type^1);
        if(g[row][col]!='\\')
            dfs(row,col,type^3);
        
            
    }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        g=grid;
        vis.resize(n,vector<vector<bool>>(m,vector<bool>(4)));
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int type=0;type<4;type++)
                {
                    if(!vis[i][j][type])
                    {
                        dfs(i,j,type);
                        c++;
                    }
                }
            }
        }
                   return c;
    }
};