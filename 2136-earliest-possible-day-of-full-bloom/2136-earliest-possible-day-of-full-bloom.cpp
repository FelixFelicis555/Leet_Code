class Solution {
public:
   static bool cmp(const pair<int,int>&a,const pair<int,int>&b)
    {
        return a.second>b.second;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>v;
        int n=plantTime.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({plantTime[i],growTime[i]});
        }
        sort(begin(v),end(v),cmp);
        
        int start=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            start+=v[i].first;
            ans=max(ans,start+v[i].second);
        }
        return ans;
    }
};