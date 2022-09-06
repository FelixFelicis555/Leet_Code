class Solution {
public:

    vector<vector<int>> powerSet(vector<int>&nums,int n)
  {
    int pow_set_size=pow(2,n);
    
    vector<vector<int>>ans;

    sort(nums.begin(),nums.end());
    vector<string>cur;

    for(int counter=0;counter<pow_set_size;counter++)
    {
        vector<int>subset;
        string temp=" ";
        for(int j=0;j<n;j++)
        {
            if((counter &(1<<j))!=0)
            {
                subset.push_back(nums[j]);
                temp+=to_string(nums[j])+'$';
            }
        }
        if(find(cur.begin(),cur.end(),temp)==cur.end())
        {
            ans.push_back(subset);
            cur.push_back(temp);
        }

    }
    return ans;
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;
        res=powerSet(nums,n);
        return res;
    }
};