class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int p=find(begin(nums),end(nums),k)-nums.begin();
         unordered_map<int,int>cnt;
        int res=0;
        for(int i=p,bal=0;i<nums.size();i++)
        {
            bal+=nums[i]==k?0:nums[i]<k?-1:1;
            ++cnt[bal];
        }
        for(int i=p,bal=0;i>=0;i--)
        {
            bal+=nums[i]==k?0:nums[i]<k?-1:1;
            res+=cnt[-bal]+cnt[-bal+1];
            
        }
        return res;
    }
};