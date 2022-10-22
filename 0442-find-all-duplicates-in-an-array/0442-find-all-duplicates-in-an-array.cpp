class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       unordered_map<int,int>m;
        vector<int>ans;
        for(auto num:nums)
        {
            m[num]++;
            if(m[num]==2)
                ans.push_back(num);
    
        }
        return ans;
    }
};