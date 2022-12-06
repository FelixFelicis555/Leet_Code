class Solution {
public:
    int count[20005];
    int dp[20005];
    int deleteAndEarn(vector<int>& nums) {
       int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        memset(dp,0,sizeof(dp));
        memset(count,0,sizeof(count));
        for(auto &x:nums)
            count[x]+=x;
        dp[0]=0;
        dp[1]=count[1];
        for(int i=2;i<=maxi;i++)
            dp[i]=max(count[i]+dp[i-2],dp[i-1]);
        return dp[maxi];
    }
};