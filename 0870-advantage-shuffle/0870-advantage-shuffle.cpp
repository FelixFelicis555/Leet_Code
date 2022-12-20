class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int>m(nums1.begin(),nums1.end());
        vector<int>ans(nums1.size());
        for(int i=0;i<nums2.size();i++)
        {
            auto it=m.upper_bound(nums2[i]);
            if(it==m.end())
            {
                ans[i]=*(m.begin());
                m.erase(m.begin());
            }
            else
            {
                ans[i]=*it;
                m.erase(it);
            }
        }
        return ans;
    }
};