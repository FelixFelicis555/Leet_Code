class Solution {
public:
    bool IsBitSet(int bit,int num)
    {
        return ((1LL<<bit) & num)>0;
    }   
    int minimizeXor(int num1, int num2) {
        int n=__builtin_popcount(num2);
        int x=0;
        for(int j=30;j>=0;j--)
        {
            if(n==0)
                break;
            if(IsBitSet(j,num1))
            {
                x^=(1<<j);
            n--;
            }   
        } 
        int bit=0;
        while(n>0)
        {
            while(IsBitSet(bit,num1))
            {
                bit++;
            } 
            x^=(1<<bit);
            bit++;
            n--;
        } 
        return x;
    }
};