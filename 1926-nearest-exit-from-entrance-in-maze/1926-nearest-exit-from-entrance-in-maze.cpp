class Solution {
public:
    int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
       int m=maze.size();
        int n=maze[0].size();
        int moves=1;
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                auto cur=q.front();
                q.pop();
                for(auto d:dir)
                {
                    int x=cur.first+d[0],y=cur.second+d[1];
                    if(x>=0 && x<m && y>=0 && y<n && maze[x][y]!='+')
                    {
                        if(x==0 || x==m-1 || y==0 || y==n-1)
                        {
                            if(!(x==entrance[0] && y==entrance[1]))
                                return moves;
                        }
                        q.push({x,y});
                        maze[x][y]='+';
                    }
                }
            }
            moves++;
        }
        return -1; 
    }
};