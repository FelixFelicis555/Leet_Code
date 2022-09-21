class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
       vector<pair<int,int>>v;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++)
        {
            v.push_back({efficiency[i],speed[i]});
        } 
        sort(v.begin(),v.end());
        long sum=0,ans=0;
        for(int i=n-1;i>=0;i--)
        {
            sum+=v[i].second;
           pq.push(v[i].second);

            while(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            } 
            ans=max(ans,sum*v[i].first);
        } 
        return ans%(1000000007);
    }
    
};