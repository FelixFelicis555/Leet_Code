class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int cur=0;
        int max=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] & 1)
            {
                max=max>++cur?max:cur;
            }
            else
                cur=0;
        }
        return max;
    }
};