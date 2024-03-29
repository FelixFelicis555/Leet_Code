class Solution {
public:
    int p[100005];
    vector<pair<int,int>> adj[100005];
    
    static bool comp(vector<int> &a, vector<int> &b){
        return a[2]<b[2];
    }
    
    int find(int u){
        if(p[u]==u)
            return u;
        return p[u]=find(p[u]);
    }
    
    void merge(int x, int y){
        p[find(x)]=find(y);
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        for(int i=0;i<n;i++){
            p[i]=i;
        }
        int m=meetings.size();
     //   sort(meetings.begin(),meetings.end(),comp);
        for(int i=0;i<m;i++){
            adj[meetings[i][2]].push_back({meetings[i][0], meetings[i][1]});
        }
        merge(0,firstPerson);
        for(int i=1;i<100005;i++){
            for(int j=0;j<adj[i].size();j++){
                int x=adj[i][j].first;
                int y=adj[i][j].second;
                merge(x,y);
            }
            for(int j=0;j<adj[i].size();j++){
                int x=adj[i][j].first;
                int y=adj[i][j].second;
                if(find(x)!=find(0)){
                    p[x]=x;
                    p[y]=y;
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(find(i)==find(0))
                ans.push_back(i);
        }
        return ans;
    }
};