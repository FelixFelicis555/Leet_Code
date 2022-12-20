class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
       vector<vector<int>> adj(102, vector<int>(102, 1e5));
        
        for(vector<int> i: edges){
            adj[i[0]][i[1]]=i[2];
            adj[i[1]][i[0]]=i[2];
        }
        
        for(int k=0;k<n;k++){
          for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][k]+adj[k][j] < adj[i][j])
                    adj[i][j]=adj[i][k]+adj[k][j];
            }
          }
        }
        
        int maxd=1e9;
        int ans=0;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(i!=j && adj[i][j]<=distanceThreshold)
                    c++;
            }
                if(c<=maxd){
                    ans=i;
                    maxd=c;
            }
        }
        return ans; 
    }
};