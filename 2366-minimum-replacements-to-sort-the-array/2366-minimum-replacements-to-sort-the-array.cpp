class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
         long long ans=0;
        
        // Where to start?
        
        // we will traverse from  the end of an array
        
        // How to break an element?
        
        // You need to break an element by doing operations on current element which are less than element right to it.
        
        // By doing so,we get an optimal solution
        long long max=nums.back();
        for(int i=nums.size()-2;i>=0;i--)
        {
           const int ops=(nums[i]-1)/max;
            ans+=ops;
            max=nums[i]/(ops+1);
        }
        return ans;
    }
};