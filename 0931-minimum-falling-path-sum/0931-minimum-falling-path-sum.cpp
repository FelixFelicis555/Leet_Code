class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
       int n=matrix.size();
        int m=matrix[0].size();
        int t[n][m];
        memset(t,0,sizeof(t));
        for(int i=0;i<m;i++)
            t[0][i]=matrix[0][i];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                t[i][j]+=matrix[i][j]+min(min(t[i-1][j], t[i-1][min(j+1,m-1)]), t[i-1][max(j-1, 0)]);
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<m;i++)
            mini=min(mini,t[n-1][i]);
        return mini;
    }
};