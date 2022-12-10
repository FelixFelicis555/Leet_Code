class Solution {
public:
    int maxJump(vector<int>& stones) {
        vector<int>st(stones);
        return max(st[1] - st[0], transform_reduce(
        begin(st) + 2, end(st), begin(st), 0, 
        [](int a, int b){ return max(a, b); },
        [](int i, int j){ return i - j; }));
    }
};