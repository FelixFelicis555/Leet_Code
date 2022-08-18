class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int min=*min_element(nums.begin(),nums.end());
        int max=*max_element(nums.begin(),nums.end());
        int res1=0,res2=0;
        if(min==max)
         return min;   
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=1;i<nums.size();i++)
        {
            if((nums[i]^nums[i-1])==0)
            {
                 ans=nums[i];
                break;
            }
        } 
        return ans;
    }
};