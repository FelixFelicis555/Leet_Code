class Solution {
public:
    vector<int>v;
    int n;
    Solution(vector<int>& nums) {
        v=nums;
        n=nums.size();
    }
    
    vector<int> reset() {
        return v;
    }
    
    vector<int> shuffle() {
        vector<int>shuffled=v;
        int sz=n;
        for(int i=n-1;i>=0;i--)
        {
            int j=rand()%sz;
            swap(shuffled[i],shuffled[j]);
            sz--;
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */