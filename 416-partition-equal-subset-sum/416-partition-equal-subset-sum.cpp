class Solution {
vector<vector<int>>dp;
    bool subsetSum(vector<int>&nums,int n,int pos,int sum)
    {
        if(sum==0)
            return true;
        else if(pos>=n || sum<0)
            return false;
        if(dp[pos][sum]!=-1)
            return dp[pos][sum];
        return dp[pos][sum]=subsetSum(nums,n,pos+1,sum-nums[pos]) || subsetSum(nums,n,pos+1,sum);
    }   
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n= nums.size();
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum & 1)
            return false;
        dp.clear();
        dp.resize(n+1,vector<int>(sum/2+1,-1));
        return subsetSum(nums,n,0,sum/2);
    }
};