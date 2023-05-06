class Solution {
public:
    int m=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
       int n=nums.size();
      sort(begin(nums),end(nums));
       
        int pow[n+1];
        pow[0]=1;
        for(int i=1;i<n;i++)
        {
            pow[i]=(pow[i-1]*2)%m;
        }
        int left=0,right=n-1;
        int ans=0;
        while(left<=right)
        {
            if(nums[left]+nums[right]<=target)
            {
                ans+=pow[right-left];
                ans%=m;
                left++;
            }
            else
            {
                right--;
            }
        }
        return ans;
    }
};