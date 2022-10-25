class Solution {
public:
     bool isSafe(int r,int c,vector<string>&board,int n)
    {
        // check upper-diagonal
        int duprow=r;
        int dupcol=c;
        while(r>=0 && c>=0)
        {
            if(board[r][c]=='Q')
               return false;
               r--;
               c--;
        }
               c=dupcol;
               r=duprow;
               while(c>=0)
               {
                   if(board[r][c]=='Q')
                       return false;
                   c--;
               }
       r=duprow;
      c=dupcol;
               while(r<n &&c>=0)
               {
                   if(board[r][c]=='Q')
                       return false;
                   r++;
                   c--;
               }
               
               
               return true;
               
    }
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,board,n))
            {
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        solve(0,board,ans,n);
        return ans.size();
    }
};