class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
    {
      vector<int>v(nums);
      sort(v.begin(),v.end());
    for(int i=1;i<v.size();i++)
        v[i]+=v[i-1];
    vector<int>q(queries);
    vector<int>ans;
    for(int x:q)
    {
        int idx=upper_bound(v.begin(),v.end(),x)-v.begin();
        ans.push_back(idx);
    }
    return ans;
    }
};