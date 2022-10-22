class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int,int>m;
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(m.find(nums[i])!=m.end())
                m[nums[i]]+=1;
            else
                m[nums[i]]=1;
        }
        for(int i=1;i<=n;i++)
        {
            if(m.find(i)==m.end())
                ans.push_back(i);
        }
        return ans;
    }
};