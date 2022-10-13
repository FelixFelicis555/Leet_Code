class Solution {
public:
    unordered_map<int,int>par;
    int find(int a)
    {
        if(par[a]==a)
            return a;
        return par[a]=find(par[a]);
    }
    void merge(int a,int b)
    {
        if(par.find(a)==par.end())
            par[a]=a;
        if(par.find(b)==par.end())
            par[b]=b;
        int x=find(a);
        int y=find(b);
        par[x]=y;
    }
    unordered_map<int,vector<int>>findGroups(){
         unordered_map<int, vector<int>> groups;
        for(auto it:par)
        {
            groups[find(it.first)].push_back(it.first);
            // For same absolute root node/par,we are pushing all of it's children
        }
        return groups;
    }
    void reset()
    {
        par.clear();
    }
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        map<int,vector<pair<int,int>>>mp;
        // Sorted the elements based on it's  value
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mp[matrix[i][j]].push_back({i,j});
            }
        }
        vector<int>rank(n+m,0);
        for(auto it:mp)
        {
            reset();
            auto x=it.second;
            for(int j=0;j<x.size();j++)
                merge(x[j].first,n+x[j].second);
            
        
        for(auto t:findGroups())
        {
            int maxi=0;
            for(int i=0;i<t.second.size();i++)
                maxi=max(maxi,rank[t.second[i]]);
            for(int i=0;i<t.second.size();i++)
                rank[t.second[i]]=maxi+1;
        }
        
        for(int j=0;j<x.size();j++)
        {
             matrix[x[j].first][x[j].second]=rank[x[j].first];
        }
        }
        return matrix;
    }
};