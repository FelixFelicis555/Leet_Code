class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>ans;
        if(m==0)
            return ans;
        vector<vector<bool>>seen(m,vector<bool>(n,false));
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        int x=0,y=0,di=0;
        for(int i=0;i<m*n;i++)
        {
            ans.push_back(matrix[x][y]);
            seen[x][y]=true;
            int newX=x+dr[di];
            int newY=y+dc[di];
            if(newX>=0 && newX<m && newY>=0 && newY<n && !seen[newX][newY])
            {
                x=newX;
                y=newY;
            }
            else
            {
                di=(di+1)%4;
                x+=dr[di];
                y+=dc[di];
            }
        }
        return ans;
        
    }
};