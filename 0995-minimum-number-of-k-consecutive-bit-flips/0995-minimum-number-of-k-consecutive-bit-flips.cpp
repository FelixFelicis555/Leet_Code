class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        queue<int>flips;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                if(flips.empty() || flips.size()%2==0)
                {
                    count++;
                    flips.push(i+k-1);
                }
            }
            else
            {
                if(flips.size()%2!=0)
                {
                    count++;
                    flips.push(i+k-1);
                }
            }
            if(!flips.empty() && flips.front()<=i)flips.pop();
        }
        return flips.empty()?count:-1;
    }
};