class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()==0 || nums.size()<3)
            return false;
        int minOne=INT_MAX;
        int minTwo=INT_MAX;
        for(int num:nums)
        {
            if(num<minOne)
            {
                minOne=num;
            }
            if(num>minOne)
            {
                minTwo=min(num,minTwo);
            }
            if(num>minTwo)
            {
                return true;
            }
        }
        return false;
    }
};