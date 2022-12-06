class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       int n=nums.size();
       if(n==0)
           return 0;
        sort(nums.begin(),nums.end());
        int min=INT_MAX;
        int closed=0;
        for(int i=0;i<nums.size()-2;i++)
        {
            
            
            int l=i+1;
            int r=nums.size()-1;
            while(l<r)
            {
                int sum=nums[i]+nums[l]+nums[r];
                if(abs(sum-target)<min)
                {
                    min=abs(sum-target);
                    closed=sum;
                }
                if(sum<target)
                  l++;
                else
                    r--;
            }
               
        }
        return closed;
    }
};