class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        bool sum[201] = {};
    sort(begin(nums), end(nums));
    for (int i = 0, j = nums.size() - 1; i < j;)
        sum[nums[i++] + nums[j--]] = true;
    return count(begin(sum), end(sum), true);
    }
};