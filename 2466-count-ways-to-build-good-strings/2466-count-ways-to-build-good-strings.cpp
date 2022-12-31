class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
       int dp[100001] = {};
    function<int(int)> dfs = [&](int i){
        if (i > high)
            return 0;
        if (dp[i] == 0)
            dp[i] = (1 + (i >= low ? 1 : 0) + dfs(i + zero) + dfs(i + one)) % 1000000007;
        return dp[i] - 1;
    };
    return dfs(0);  
    }
};