class Solution {
public:
     int cnt_p[10002][10] = {}, cnt_s[10002][10] = {};
int dp_p[10002][10][10] = {}, dp_s[10002][10][10] = {};
int countPalindromes(string s) {
    for (int i = 0, j = s.size() - 1; i < s.size(); ++i, --j)
        for (int d = 0; d < 10; ++d) {
            cnt_p[i + 1][d] = cnt_p[i][d] + (s[i] == '0' + d);
            cnt_s[j][d] = cnt_s[j + 1][d] + (s[j] == '0' + d);
        }
    for (int i = 1; i < s.size(); ++i) {
        for(int n1 = 0; n1 < 10; ++n1)
            for(int n2 = 0; n2 < 10; ++n2)
                dp_p[i][n1][n2] += dp_p[i - 1][n1][n2];
        for(int n1 = 0; n1 < 10; ++n1)
            dp_p[i][n1][s[i] - '0'] += cnt_p[i][n1];
    }
    for(int i = s.size() - 2; i >= 0; --i) {
        for(int n1 = 0; n1 < 10; ++n1)
            for(int n2 = 0; n2 < 10; ++n2)
                dp_s[i][n1][n2] += dp_s[i + 1][n1][n2];
        for(int n1 = 0; n1 < 10; ++n1)
            dp_s[i][s[i] - '0'][n1] += cnt_s[i + 1][n1];
    }
    long long res = 0;
    for (int i = 1; i < s.size() - 1; ++i)
        for(int n1 = 0; n1 < 10; ++n1)
            for(int n2 = 0; n2 < 10; ++n2) 
                res = (res + (long long)dp_p[i - 1][n1][n2] * dp_s[i + 1][n2][n1]) % 1000000007;
    return res;

        
    }
};