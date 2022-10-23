class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<long long>ind(nums.size()),cost_l(nums.size());
        iota(begin(ind),end(ind),0);
        sort(begin(ind),end(ind),[&](int i,int j){
          return nums[i]<nums[j];
        });
        for(long long i=0,sum=0;i<nums.size()-1;i++)
        {
            sum+=cost[ind[i]];
            cost_l[i+1]= cost_l[i]+sum*(nums[ind[i+1]]-nums[ind[i]]);
        }
        long long res=cost_l.back(),cost_r=0;
        for(long long j=nums.size()-1,sum=0;j>0;j--)
        {
          sum+=cost[ind[j]];
            cost_r+=sum*(nums[ind[j]]-nums[ind[j-1]]);
          res=min(res,cost_l[j-1]+cost_r);
        }
        return res;
    }
};