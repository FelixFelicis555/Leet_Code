class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxsf=nums[0],minsf=nums[0];
        int ans=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            int temp=maxsf;
            maxsf=max(nums[i],max(maxsf*nums[i],minsf*nums[i]));
            minsf=min(nums[i],min(temp*nums[i],minsf*nums[i]));
            ans=max(ans,maxsf);
        }
        return ans;
    }
};