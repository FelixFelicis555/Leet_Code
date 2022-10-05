class Solution {
public:
    double myPow(double x, int n) {
       long long int p=n;
       double ans=1.0;
       if(n<0)
       {
           p=-p;
       } 
        if(n==1)
            return x;
        while(p>0)
        {
            if(p%2==1)
        ans*=x;
            p=p/2;
            x*=x;
            
        } 
        if(n<0)
         return (1/ans);
        else
            return ans;
    }
};