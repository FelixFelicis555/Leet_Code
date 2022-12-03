class Solution {
public:
     int t[601][101][101];
  
    int ans(int i,vector<string>& strs, int size, int m, int n){
       
        if(size==0)
            return t[i][m][n]=0;
        if(m==0 && n==0)
            return t[i][m][n]=0;
        if(t[i][m][n]!=-1)
            return t[i][m][n];
        
        int zeroes=0,ones=0;
        
        for(char ch : strs[i]){
            if(ch=='0')
                zeroes++;
            if(ch=='1')
                ones++;
        }
        
     
        if(zeroes<=m && ones<=n)
            t[i][m][n]=max(ans(i+1,strs,size-1,m-zeroes,n-ones)+1, ans(i+1,strs,size-1,m,n));
        else
           t[i][m][n]=ans(i+1,strs,size-1,m,n);
        return t[i][m][n];
            
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
         int size=strs.size();
        memset(t,-1,sizeof(t));
        return ans(0,strs,size,m,n);
    }
};