class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       int ans=0,cur=0;
        unordered_set<int>s;
        for(int i=0,j=0;j<nums.size();j++)
        {
            while(s.find(nums[j])!=s.end())
            {
                s.erase(nums[i]);
                cur-=nums[i];
                i++;
            }
            s.insert(nums[j]);
            cur+=nums[j];
            ans=max(ans,cur);
        }
        return ans;
    }
};