class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int n=nums.size();
        k=k%n;
        int i,j;
        for( i=n-k,j=n-1;i<j;i++,j--)
        {
            swap(nums[i],nums[j]);
        }
        for(i=0,j=n-k-1;i<j;i++,j--)
        {
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin(),nums.end());
         
    }
};