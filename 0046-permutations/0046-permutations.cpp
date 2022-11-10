class Solution {
public:
    vector<vector<int>>help(vector<int>&nums)
    {
        if(nums.size()==0)
            return {{}};
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++)
        {
            vector<int>temp;
            temp.push_back(nums[i]);
            vector<int>v;
            for(int j=0;j<nums.size();j++)
            {
                if(i!=j)
                  v.push_back(nums[j]);  
            }
            vector<vector<int>>nums1=help(v);
            for(auto a :nums1)
            {
                a.push_back(nums[i]);
                ans.push_back(a);
            }
        }
        return ans;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        return help(nums);
    }
};