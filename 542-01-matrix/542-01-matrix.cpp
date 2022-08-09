class Solution {
public:
    bool cmp(pair<int,int> &p,int n,int m)
    {
        return p.first>=0 && p.first<n && p.second>=0 && p.second<m;
    }    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        vector<vector<int>> dist(r,vector<int>(c,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(!mat[i][j])
                {
                    dist[i][j]=0;
                    q.push({i,j});
                }    
            }    
        } 
        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,1,0,-1};
        while(!q.empty())
        {
            pair<int,int>p=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
              pair<int,int> n={p.first+dx[i],p.second+dy[i]};
              if(cmp(n,r,c) && dist[n.first][n.second]==INT_MAX)
              {
                  dist[n.first][n.second]=dist[p.first][p.second]+1;
                  q.push(n);
              }    
            }    
        } 
        return dist;
        
    }
};