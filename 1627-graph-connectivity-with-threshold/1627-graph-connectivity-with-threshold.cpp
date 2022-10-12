class Solution {
public:
    int par[10005];
    int find(int a)
    {
        if(par[a]==a)
            return a;
        return par[a]=find(par[a]);
    }
    void merge(int a,int b)
    {
        par[a]=b;
    }
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
       for(int i=0;i<10005;i++)
           par[i]=i;
        for(int i=threshold+1;i<=n;i++)
        {
            for(int j=1;j<=n && i*j<=n;j++)
            {
                int x=find(i);
                int y=find(i*j);
                merge(x,y);
            }
        }
        vector<bool>ans;
        for(auto it:queries)
        {
            if(find(it[0])==find(it[1]))
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};