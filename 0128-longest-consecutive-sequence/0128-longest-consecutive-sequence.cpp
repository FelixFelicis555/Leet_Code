class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s.find(nums[i]-1)!=s.end())
                continue;
            else
            {
                int cur=nums[i];
                int count=0;
                while(s.find(cur)!=s.end())
                {
                    count++;
                    cur++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};