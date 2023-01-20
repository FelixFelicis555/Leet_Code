class Solution {
public:
    void backtrack(vector<int>&nums,vector<int>&sequence,set<vector<int>>&result,int i)
    {
        if(i==nums.size())
        {
            if(sequence.size()>=2)
            {
                result.insert(sequence);
            }
            return;
        }
        
        if(sequence.empty() || sequence.back()<=nums[i])
        {
            sequence.push_back(nums[i]);
            backtrack(nums,sequence,result,i+1);
            sequence.pop_back();
        }
        backtrack(nums,sequence,result,i+1);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
       set<vector<int>>result;
        vector<int>sequence;
        backtrack(nums,sequence,result,0);
        return vector(result.begin(),result.end());
    }
};