class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int swap=0,noswap=1;
        for(int i=1;i<n;i++)
        {
            int x=INT_MAX,y=INT_MAX;
            if(nums1[i]>nums2[i-1] && nums2[i]>nums1[i-1])
            {
                x=min(x,noswap);
                y=min(y,swap+1);
            }
            if(nums1[i]>nums1[i-1] && nums2[i]>nums2[i-1])
            {
                x=min(x,swap);
                y=min(y,noswap+1);
            }
            swap=x;
            noswap=y;
        }
        return min(swap,noswap);
    }
};