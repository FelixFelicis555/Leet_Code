class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int n=nums.size();
        if(n==0 || n==1)
            return n;
        int res[n];
        int j=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]!=nums[i+1])
                res[j++]=nums[i];
        }
        res[j++]=nums[n-1];
        for(int i=0;i<j;i++)
            nums[i]=res[i];
        return j;  
    }
};