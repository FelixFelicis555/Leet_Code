class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int n=nums.size();
        int len=INT_MAX;
        int windowSum=0;
        for(int right=0;right<n;right++)
        {
            windowSum+=nums[right];
            while(windowSum>=target && left<=right)
            {
                len=min(len,right-left+1);
                windowSum-=nums[left];
                left++;
            }
        }
        if(len==INT_MAX)
            return 0;
        return len;
    }
};