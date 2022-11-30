class Solution {
public:
    int thirdMax(vector<int>& nums) {
       int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN;
        bool flag=false;
        for(int num:nums)
        {
             if(num == INT_MIN) flag = true;
            if(num==max1 || num==max2 || num<=max3)
                continue;
            if(num>max1)
            {
                max3=max2;
                max2=max1;
                max1=num;
            }
            else if(num>max2)
            {
                max3=max2;
                max2=num;
            }
            else
                max3=num;
        }
        if(max2==INT_MIN || max3==INT_MIN && !flag)
            return max1;
        return max3;
    }
};