class Solution {
public:
    int rev(int num)
    {
        int res=0;
        while(num>0)
        {
           res=res*10+num%10;
            num=num/10;
        }
        return res;
    }
    int countDistinctIntegers(vector<int>& nums) {
       unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]=1;
    
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(rev(nums[i]))==m.end())
                
                m[rev(nums[i])]=1;
        }
        int ans=m.size();
        return ans;
    }
};