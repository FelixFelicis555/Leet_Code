class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        set<int>s;
        
        for(auto x:nums1)
            m[x]++;
        for(auto x:nums2)
        {
            if(m.find(x)!=m.end())
             s.insert(x);
            
        }
        vector<int>ans(s.begin(),s.end());
        return ans;
    }
};