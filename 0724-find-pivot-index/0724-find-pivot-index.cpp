class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total=0;
        for(int num:nums)
            total+=num;
        int curSum=0;
        for(int i=0;i<nums.size();i++)
        {
            // Cursum is upto i not inclusive of i.
           if(curSum==total-curSum-nums[i])
               return i;
            // updating the cursum
           curSum+=nums[i];
        }
        return -1;
    }
};