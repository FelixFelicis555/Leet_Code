class Solution {
public:
    bool validGroup(vector<int>&nums,int m,int k)
    {
        int count=1;
        long sum=0;
        for(int num:nums)
        {
            sum+=num;
            if(sum>m)
            {
                count++;
                sum=num;
                if(count>k)
                    return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int left=*max_element(nums.begin(),nums.end());
        int right=accumulate(nums.begin(),nums.end(),0);
        if(k==1)
            return right;
        while(left<right)
        {
            long mid=left+(right-left)/2;
            if(validGroup(nums,mid,k))
                right=mid;
            else
                left=mid+1;
        }
        return right;
    }
};