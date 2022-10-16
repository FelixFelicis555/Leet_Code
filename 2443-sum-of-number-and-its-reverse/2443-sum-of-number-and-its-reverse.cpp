class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        int n1=num/2;
        auto rev=[](int n){
            int rn=0;
            while(n)
            {
                rn=rn*10+n%10;
                n/=10;
            }
            return rn;
        };
        while(n1<=num)
        {
            if(n1+rev(n1)==num)
                return true;
            n1++;
        }
        return false;
    }
};