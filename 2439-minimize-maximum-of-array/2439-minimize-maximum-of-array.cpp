class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
       long long minmax=0,sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            minmax=max((sum+i)/(i+1),minmax);
        }
        return minmax;
    }
};