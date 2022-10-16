class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]=1;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=n-1;i>=0;i--)
        {
            if(m[-nums[i]])
                return nums[i];
        }
        return -1;
    }
};