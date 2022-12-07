class Solution {
public:
    int trailingZeroes(int n) {
        int temp=0,sum=0;
        while(n/5 >0)
        {
            temp=n/5;
            sum+=temp;
            n=temp;
        }
        return sum;
    }
};