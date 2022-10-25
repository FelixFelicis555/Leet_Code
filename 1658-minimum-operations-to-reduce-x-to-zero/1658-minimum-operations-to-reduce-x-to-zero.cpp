class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        bool found=false;
        int n=nums.size();
        int sum=0;
        for(int x:nums)
            sum+=x;
        int target=sum-x;
        int i=0;
        int cur=0;
        int maxlen=0;
        for(int j=0;j<n;j++)
        {
            cur+=nums[j];
            while(i<=j && cur>target)
            {
                cur-=nums[i];
                i++;
            }
            if(cur==target)
            {
                found=true;
                maxlen=max(maxlen,j-i+1);
            }
            
        }
        return found?n-maxlen:-1;
    }
};