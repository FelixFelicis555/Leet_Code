class Solution {
public:
    
    int minimumAverageDifference(vector<int>& nums) {
       long long int sum1=0,sum2=0;
        long long int x=INT_MAX;
        
        for(int i=0;i<nums.size();i++)
            sum1+=nums[i];
        long long int temp=sum1;
        long long int n=nums.size();
        long long int ans=0;
        for(int i=0;i<n;i++)
        {
            sum2+=nums[i];
            sum1-=nums[i];
            if(i==n-1)
            {
                if(temp/n<x)
                {
                    ans=i;
                }
            }
            else if(abs(sum2/(i+1)-sum1/(n-i-1))<x)
            {
                x=abs(sum2/(i+1)-sum1/(n-i-1));
                ans=i;
            }
        }
        return ans;
    }
};