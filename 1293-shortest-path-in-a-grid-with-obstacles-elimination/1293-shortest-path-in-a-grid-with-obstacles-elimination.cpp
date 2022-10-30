class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
     queue<array<int,3>>q,q1;
        q.push({0,0,k+1});
        int steps=-1;
        while(!q.empty())
        {
            steps++;
            while(!q.empty())
            {
                auto i=q.front()[0],j=q.front()[1],k=q.front()[2];
                q.pop();
                if(i==grid.size() -1 && j==grid[0].size()-1)
                    return steps;
                if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
                    continue;
                k-=(1&grid[i][j]);
                if(k>0 && (grid[i][j] >>1)<k)
                {
                    grid[i][j]=(1 & grid[i][j])+(k<<1);
                    q1.push({i+1,j,k});
                    q1.push({i,j+1,k});
                    q1.push({i-1,j,k});
                    q1.push({i,j-1,k});
                }
            }
            swap(q,q1);
        }
        return -1;
    }
};