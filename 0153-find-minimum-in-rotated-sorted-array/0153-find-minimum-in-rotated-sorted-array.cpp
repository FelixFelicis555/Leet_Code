class Solution {
public:
    int solve(vector<int>&nums,int low,int high)
    {
       if(high<low)
           return nums[0];
        if(high==low)
            return nums[low];
        int mid=low+(high-low)/2;
        // Check if element (mid+1) is minimum element. Consider
    // the cases like {3, 4, 5, 1, 2}
    if (mid < high && nums[mid + 1] < nums[mid])
        return nums[mid + 1];
 
    // Check if mid itself is minimum element
    if (mid > low && nums[mid] < nums[mid - 1])
        return nums[mid];
 
    // Decide whether we need to go to left half or right
    // half
    if (nums[high] > nums[mid])
        return solve(nums, low, mid - 1);
    return solve(nums, mid + 1, high);
    }
    int findMin(vector<int>& nums) {
         int low=0;
        int high=nums.size()-1;
        return solve(nums,low,high);
    }
};