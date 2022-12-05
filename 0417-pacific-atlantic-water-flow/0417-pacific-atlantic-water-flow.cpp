class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={-1,0,1,0};
    void dfs(vector<vector<int>>&mat,vector<vector<int>>&g,int x,int y)
    {
        g[x][y]=1;
        for(int i=0;i<4;i++)
        {
            int xx=dx[i]+x;
            int yy=dy[i]+y;
            if(xx>=0 && xx<mat.size() && yy>=0 && yy<mat[0].size() && !g[xx][yy] && mat[xx][yy]>=mat[x][y])
                dfs(mat,g,xx,yy);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>matrix(heights);
        vector<vector<int>>ans;
        int n=matrix.size();
        int m=matrix[0].size();
        if(n==0 || m==0)
            return ans;
        vector<vector<int>>pac(n,vector<int>(m,0));
        vector<vector<int>>atl(n,vector<int>(m,0));
         for(int i=0;i<n;i++){
            if(!pac[i][0]){
                dfs(matrix, pac, i, 0);
            }
        }
         for(int i=0;i<m;i++){
            if(!pac[0][i]){
                dfs(matrix, pac, 0, i);
            }
        }
         for(int i=0;i<n;i++){
            if(!atl[i][m-1]){
                dfs(matrix, atl, i, m-1);
            }
        }
         
         for(int i=0;i<m;i++){
            if(!atl[n-1][i]){
                dfs(matrix, atl, n-1, i);
            }
        }
        
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (pac[i][j] && atl[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};