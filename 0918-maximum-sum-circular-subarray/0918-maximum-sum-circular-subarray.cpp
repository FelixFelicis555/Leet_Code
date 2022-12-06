class Solution {
public:
    int n;
    int maxSumSubarray(vector<int>&nums)
    {
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum>maxi)
            {
                maxi=sum;
            }
            if(sum<0)
                sum=0;
        }
        return maxi;
    }
    int minSumSubarray(vector<int>&nums)
    {
       int mini=INT_MAX;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum<mini)
                mini=sum;
            if(sum>0)
                sum=0;
            
        }
        return mini;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        n=nums.size();
        int sum=0;
        for(auto &x:nums)
            sum+=x;
        int minsum=minSumSubarray(nums);
        int maxsum=maxSumSubarray(nums);
        if(maxsum>0)
            return max(maxsum,sum-minsum);
        return maxsum;
        
    }
};