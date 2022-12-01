class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        int t[n][m];
        memset(t,0,sizeof(t));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i==n-1 && j==m-1)
                {
                    if(dungeon[i][j]>=0)
                        t[i][j]=1;
                    else
                        t[i][j]=1+abs(dungeon[i][j]);
                }
                else if(i==n-1)
                {
                    if(dungeon[i][j]>=t[i][j+1])
                        t[i][j]=1;
                    else
                        t[i][j]=t[i][j+1]-dungeon[i][j];
                }
                else if(j==m-1)
                {
                    if(dungeon[i][j]>=t[i+1][j])
                        t[i][j]=1;
                    else
                        t[i][j]=t[i+1][j]-dungeon[i][j];
                }
                else
                {
                    t[i][j]=min(dungeon[i][j]>=t[i+1][j]?1:t[i+1][j]-dungeon[i][j], dungeon[i][j]>=t[i][j+1]?1:t[i][j+1]-dungeon[i][j]);  
                }
            }
        }
        return t[0][0];
    }
};