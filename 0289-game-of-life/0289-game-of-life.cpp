class Solution {
public:
    bool isValidate(int x,int y,vector<vector<int>>&board)
    {
        return (x>=0 && x<board.size() && y>=0 && y<board[0].size());
    }
    void gameOfLife(vector<vector<int>>& board) {
       vector<int>dx={0,0,1,1,1,-1,-1,-1};
        vector<int>dy={1,-1,1,-1,0,0,1,-1};
        
        int n=board.size();
        int m=board[0].size();
        for(int r=0;r<n;r++)
        {
            for(int c=0;c<m;c++)
            {
                int count_live_neighbors=0;
                for(int i=0;i<8;i++)
                {
                    int curr_x=r+dx[i];
                    int curr_y=c+dy[i];
                    if(isValidate(curr_x,curr_y,board) && abs(board[curr_x][curr_y])==1)
                    {
                        count_live_neighbors++;
                    }
                }
                if(board[r][c]==1 &&(count_live_neighbors<2|| count_live_neighbors>3))
                    board[r][c]=-1;
                if(board[r][c]==0 && (count_live_neighbors==3))
                    board[r][c]=2;
            }
        }
        for(int r=0;r<n;r++)
        {
            for(int c=0;c<m;c++)
            {
                if(board[r][c]>=1)
                    board[r][c]=1;
                else
                    board[r][c]=0;
                
            }
        }
        
    }
};