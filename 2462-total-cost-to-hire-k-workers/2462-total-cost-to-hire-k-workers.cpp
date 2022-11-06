class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int i=0,j=costs.size()-1;
        long long res=0;
        for(;i<=j && candidates;candidates--)
        {
            pq.push({costs[i],i++});
            if(i<j)
                pq.push({costs[j],j--});
        }
        while(--k>=0)
        {
            auto [sum,p]=pq.top();
            pq.pop();
            res+=sum;
            if(i<=j)
            {
                if(p<i)
                    pq.push({costs[i],i++});
                else
                    pq.push({costs[j],j--});
            }
            
        }
        return res;
        
    }
};