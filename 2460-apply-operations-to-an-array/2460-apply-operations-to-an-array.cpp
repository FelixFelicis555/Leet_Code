class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                continue;
            if(i<n-1 && nums[i]==nums[i+1])
            {
                res.push_back(nums[i]*2);
                nums[i+1]=0;
            }
            else
                res.push_back(nums[i]);
        }
        res.resize(n);
        return res;
    }
};