class Solution {
public:
    int maxJump(vector<int>& stones) {
        
       /* vector<int>st(stones);
        return max(st[1] - st[0], transform_reduce(
        begin(st) + 2, end(st), begin(st), 0, 
        [](int a, int b){ return max(a, b); },
        [](int i, int j){ return i - j; }));
        
        */
        int res=stones[1]-stones[0];
        for(int i=1;i<stones.size()-1;i++)
        {
            res=max(res,stones[i+1]-stones[i-1]);
        }
        return res;
    }
};