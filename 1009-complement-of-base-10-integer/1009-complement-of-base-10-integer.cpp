class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)
            return 1;
        int exp=log2(n)+1;
        int p=pow(2,exp)-1;
        return n^p;
    }
};