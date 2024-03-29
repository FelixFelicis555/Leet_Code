class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack<int>s;
        int n=nums.size();
        vector<int>ans(n);
        for(int i=2*n;i>=0;i--)
        {
            while(!s.empty() && s.top()<=nums[i%n])
                s.pop();
            if(i<n)
            {
                if(s.empty())
                {
                    ans[i]=-1;
                }
                else
                {
                    ans[i]=s.top();
                }
            }
            s.push(nums[i%n]);
                
        }
        return ans;
            
    }
};