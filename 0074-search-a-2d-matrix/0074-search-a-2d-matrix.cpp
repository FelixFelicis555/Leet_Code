class Solution {
public:
     bool binarySearch(vector<vector<int>>&matrix,int n,int m,int k,int x)
    {
        int l = 0, r = m - 1, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
 
        if (matrix[x][mid]==k)
        {
            return true;
        }
 
        if (matrix[x][mid]>k)
            r = mid - 1;
        if (matrix[x][mid]<k)
            l = mid + 1;
    }
        return false;
    }
    bool findrow(vector<vector<int>>&matrix,int n,int m,int k)
    {
        int l=0,r=n-1,mid;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(matrix[mid][0]==k)
                return true;
            if(matrix[mid][m-1]==k)
                return true;
            if(k>matrix[mid][0] && k<matrix[mid][m-1])
             return binarySearch(matrix,n,m,k,mid);
            if(k<matrix[mid][0])
                r=mid-1;
            if(k>matrix[mid][m-1])
                l=mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int n=matrix.size();
        int m=matrix[0].size();
        return findrow(matrix,n,m,target);
    }
};