class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        int v=2*k+1;
        vector<long long>pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++)
            pre[i]=pre[i-1]+nums[i];
        vector<int>ans(n,-1);
        for(int i=k;i<=n-k-1;i++)
        {
           long long x=pre[i+k];
            long long y=0;
            if(i-k-1>=0)
            {
                y=pre[i-k-1];
            }
            ans[i]=(x-y)/v;
        }
        return ans;
        
    }
};