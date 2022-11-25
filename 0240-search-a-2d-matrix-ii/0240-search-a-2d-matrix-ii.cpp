class Solution {
public:
    int n,m;
    bool solve(vector<vector<int>>&matrix,int t,int i,int j)
    {
        if(matrix[i][j]==t)
            return true;
        
        bool ans=false;
        if(t>matrix[i][j])
        {
            if(i+1<n)
            ans=ans| solve(matrix,t,i+1,j);
            
        }
        else
        {
            if(j-1>=0)
                ans=ans | solve(matrix,t,i,j-1);
        }
        return ans;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      n=matrix.size();
        m=matrix[0].size();
        
        return solve(matrix,target,0,m-1);
    }
};