class Solution {
public:
    vector<vector<int>>ans;
    void backtrack(int p,int n,vector<int>&nums,vector<int>&cur){
        if(p==n)
        {
            ans.push_back(cur);
            return;
        }
        cur.push_back(nums[p]);
        backtrack(p+1,n,nums,cur);
        cur.pop_back();
        backtrack(p+1,n,nums,cur);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>cur;
        int n=nums.size();
        backtrack(0,n,nums,cur);
        return ans;
    }
};