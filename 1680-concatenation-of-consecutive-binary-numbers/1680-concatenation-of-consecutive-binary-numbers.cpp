class Solution {
public:
    int concatenatedBinary(int n) {
        long long int val=0;
        int i=1;
        int mod=1e9+7;
        while(i<=n)
        {
            val=((val<<(1+int(log2(i))))%mod+i)%mod;
            i+=1;
        }
        return val;
    }
};