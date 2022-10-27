class Solution {
public:
     void findCombinations(int ind,int sum,int k,int n,vector<vector<int>>&ans,vector<int>&ds)
    {
        if(sum==n && k==0)
        {
            ans.push_back(ds);
            return;
        }
        if(sum>n)
            return;
        for(int i=ind;i<=9;i++)
        {
            if(i>n)
            {
                break;
            }
            ds.push_back(i);
            findCombinations(i+1,sum+i,k-1,n,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<vector<int>>ans;
        vector<int>ds;
        findCombinations(1,0,k,n,ans,ds);
        return ans; 
    }
};