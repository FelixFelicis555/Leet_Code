class Solution {
public:
    long long cnt[100001]={};
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum=0,res=0,unique=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(++cnt[nums[i]]==1)
                unique+=1;
            else if(cnt[nums[i]]==2)
                unique-=1;
            if(i>=k-1)
            {
                if(i>=k)
                {
                    sum-=nums[i-k];
                    if(--cnt[nums[i-k]]==1)
                        unique+=1;
                    else if(cnt[nums[i-k]]==0)
                        unique-=1;
                }
                if(unique==k)
                res=max(res,sum);
            }
        }
        return res;
    }
};