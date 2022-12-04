class Solution {
public:
    int ds[500001];
    int find(int i)
    {
        return ds[i]<0?i:ds[i]=find(ds[i]);
    }
    int minScore(int n, vector<vector<int>>& roads) {
        int res=INT_MAX;
        fill_n(begin(ds),n+1,-1);
        for(auto &r:roads)
        {
            int i=find(r[0]),j=find(r[1]);
            if(i!=j)
                ds[j]=i;
            
        }
        int i=find(1);
        for(auto&r:roads)
        {
            if(find(r[0])==i)
                res=min(res,r[2]);
            
        }
        return res;
    }
};