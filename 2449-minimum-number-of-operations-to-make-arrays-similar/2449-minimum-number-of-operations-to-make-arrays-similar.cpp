class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        sort(begin(nums),end(nums));
        sort(begin(target),end(target));
        long long res=0;
        for(int i=0,j1=0,j2=0;i<nums.size();i++)
        {
            int &j=nums[i]%2?j1:j2;
            while(nums[i]%2!=target[j]%2)
            ++j;
            
            res+=abs(nums[i]-target[j])/2;
            ++j;
    
            
        }
        return res/2;
    }
};