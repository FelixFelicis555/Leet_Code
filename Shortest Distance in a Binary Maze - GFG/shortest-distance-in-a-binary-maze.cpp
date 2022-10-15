//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int m,n;
  bool isValid(int r,int c)
  {
      return (r>=0 && r<m && c>=0 && c<n);
  }
  int dx[4]={-1,0,0,1};
  int dy[4]={0,-1,1,0};
  int bfs(vector<vector<int>>&grid,pair<int,int> src,pair<int,int> dest)
  {
      if(!grid[src.first][src.second] || !grid[dest.first][dest.second])
      return -1;
      int vis[m][n];
      memset(vis,0,sizeof(vis));
      vis[src.first][src.second]=1;
      queue<pair<pair<int,int>,int>>q;
      q.push({{src.first,src.second},0});
      while(!q.empty())
      {
          auto cur=q.front();
          pair<int,int> p={cur.first.first,cur.first.second};
          if(p.first==dest.first && p.second==dest.second)
          return cur.second;
          q.pop();
          for(int i=0;i<4;i++)
          {
              int row=p.first+dx[i];
              int col=p.second+dy[i];
              
              if(isValid(row,col) && grid[row][col] && ! vis[row][col])
              {
                  vis[row][col]=true;
                 pair<pair<int,int>,int> x={{row,col},cur.second+1};
                  q.push(x);
              }
          }
      }
      return -1;
      
  }
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        m=grid.size();
        n=grid[0].size();
        int ans=bfs(grid,source,destination);
        if(ans!=-1)
        return ans;
        else
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends