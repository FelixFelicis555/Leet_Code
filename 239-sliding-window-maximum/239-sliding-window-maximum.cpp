class Solution {
public:
    deque<int>dq;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            while(!dq.empty() && nums[i]>dq.back())
            {    
            dq.pop_back(); 
            }
            dq.push_back(nums[i]);
        }
        ans.push_back(dq.front());
       for(int i=k;i<n;i++)
       {
           if(dq.front()==nums[i-k])
           dq.pop_front();
           while(!dq.empty() && nums[i]>dq.back())
           {
               dq.pop_back();
           } 
           dq.push_back(nums[i]);
           ans.push_back(dq.front());
       }   
       return ans ;
    }
};