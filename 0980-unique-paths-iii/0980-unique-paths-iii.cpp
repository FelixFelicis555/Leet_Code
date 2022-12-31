class Solution {
public:
     int solve(vector<vector<int>>&grid,int i,int j,int count)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==-1)
            return 0;
        if(grid[i][j]==2)
        {
            if(count==0)
                return 1;
            return 0;
        }
        grid[i][j]=-1;
        int res=0;
        res+=solve(grid,i+1,j,count-1);
        res+=solve(grid,i-1,j,count-1);
        res+=solve(grid,i,j+1,count-1);
        res+=solve(grid,i,j-1,count-1);
        grid[i][j]=0;
        return res;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<int>start(2);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    start[0]=i;
                    start[1]=j;
                }
                else if(grid[i][j]==0)
                    count++;
            }
        }
        return solve(grid,start[0],start[1],count+1);
    }
};