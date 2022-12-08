class Solution {
public:
     int n,m;
    unordered_map<int, int> size; //store size of each connected component by assigning an id to every cell of the connected component which will act as a key in the map
    int vis[502][502]; //store -1 for unvisited cell and cell id for visited
    
    int dfs(int i, int j, vector<vector<int>>& grid, int islandNum){ //islandNum is the id
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0 || vis[i][j]!=-1){
            return 0;
        }
        vis[i][j]=islandNum;
        int size=1; //all connected components have same id
        size+=dfs(i+1,j,grid,islandNum);
        size+=dfs(i-1,j,grid,islandNum);
        size+=dfs(i,j+1,grid,islandNum);
        size+=dfs(i,j-1,grid,islandNum);
        return size;
    }
    int largestIsland(vector<vector<int>>& grid) {
         n=grid.size();
        m=grid[0].size();
        memset(vis,-1,sizeof(vis));
        int l=1; // set id initally as 1
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==-1){
                    size[l]=dfs(i, j, grid, l);
                    l++; //increment id for next connected component
                }
            }
        }
        
        int maxarea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){ //if we find a 0, we will try to find diff connected components attached to it, i.e, with different ids
                    int area=1;
                    set<int> s; //set assures diff id
                    if(i+1<n) 
                    s.insert(vis[i+1][j]); //vis array holds id for a particular cell
                    if(i-1>=0)
                    s.insert(vis[i-1][j]);
                    if(j+1<m) 
                    s.insert(vis[i][j+1]);
                    if(j-1>=0) 
                    s.insert(vis[i][j-1]);
                    for(int c: s){
                        area+=size[c]; //adding size for every unique connected component
                    }
                    maxarea=max(maxarea, area); //finding max atlast
                }
            }
        }
        if(maxarea!=0)
        return maxarea;
		 //if the maxarea isn't even 1 which would have been the case if atleast one 0 existed, we know the grid consists of all 1s 
        return n*m;
    }
};