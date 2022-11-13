class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            int lcm=1;
            for(int j=i;j<nums.size();j++)
            {
                if(lcm>k || k%nums[i])
                    break;
                lcm=lcm*nums[j]/gcd(lcm,nums[j]);
                if(lcm==k)
                    res+=1;
            }
        }
        return res;
    }
};