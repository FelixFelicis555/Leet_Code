class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>p(nums.size(),1);
        int temp=1;
        int n=nums.size();
        if(n==1)
        {
            p.push_back(0);
            return p;
        }
        for(int i=0;i<n;i++)
        {
            p[i]=temp;
            temp*=nums[i];
        }
        temp=1;
        for(int i=n-1;i>=0;i--)
        {
            p[i]*=temp;
            temp*=nums[i];
        }
        return p;
    }
};