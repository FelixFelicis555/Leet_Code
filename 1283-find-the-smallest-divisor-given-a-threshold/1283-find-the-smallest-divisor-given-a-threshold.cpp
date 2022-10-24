class Solution {
public:
    bool valid(vector<int>&nums,int d,int t)
    {
        for(auto n:nums)
        {
            if((t-=(n+d-1)/d)<0)
                return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
       int low=1,high=1e6;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(valid(nums,mid,threshold))
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
            
        }
};