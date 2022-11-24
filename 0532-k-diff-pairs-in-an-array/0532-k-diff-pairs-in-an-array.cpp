class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
       unordered_map<int,int>m;
        for(int i:nums)
            m[i]++;
        int ans=0;
        for(auto x:m)
        {
            if(k==0)
            {
                if(x.second>1)
                  ans++;
                
            }
            else if(m.find(x.first+k)!=m.end())
                ans++;
            
        }
        return ans;
    }
};