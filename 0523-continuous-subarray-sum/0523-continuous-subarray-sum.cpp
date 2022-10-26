class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int>m;
        m[0]=-1;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(k!=0)
                sum%=k;
            if(m.find(sum)!=m.end())
            {
                int prev=m[sum];
                if(i-prev >1)
                    return true;
            }
            else
                m[sum]=i;
            
        }
        return false;
    }
};