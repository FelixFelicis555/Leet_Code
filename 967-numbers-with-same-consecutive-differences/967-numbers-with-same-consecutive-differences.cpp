class Solution {
public:
    void dfs(int num, int i, int n, int k) {
        if (i == n) {
            ans.push_back(num);
            return;
        }
        if (num % 10 + k <= 9) dfs(num * 10 + (num % 10 + k), i + 1, n, k);
        if (k != 0 && num % 10 - k >= 0) dfs(num * 10 + (num % 10 - k), i + 1, n, k);
    }
    vector<int>ans;
   
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i= n==1?0:1;i<=9;i++)
        {
            dfs(i,1,n,k);
        } 
        return ans;
    }
};