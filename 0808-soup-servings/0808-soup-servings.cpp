class Solution {
public:
     double solve(double a, double b, vector<vector<double>> &t){
        if(a==0 && b==0)
            return t[a][b]=0.5;
        if(a==0)
            return t[a][b]=1.0;
        if(b==0)
            return t[a][b]=0.0;
        if(t[a][b]!=0)
            return t[a][b];
        
        double p,q,r,s;
        
        if(a<100){
            p=1.0;
        }
        else p=solve(a-100,b,t);
        
        if(a<75 && b<25){
            q=0.5;
        }
        else if(b<25)
            
            q=0;
        
        else if(a<75)
            q=1;
        else q=solve(a-75,b-25,t);
        
        
        if(a<50 && b<50){
            r=0.5;
        }
       
        else if(b<50)
            
            r=0;
        
        else if(a<50)
            r=1;
        else r=solve(a-50,b-50,t);
        
        
         if(a<25 && b<75){
            s=0.5;
        }
       
        else if(a<25)
            
            s=1;
        
        else if(b<75)
            s=0;
        else s=solve(a-25,b-75,t);
        
        double ans= 0.25*(p+q+r+s);
        
        return t[a][b]=ans;
            
    }
    
    double soupServings(int n) {
        int N=n;
        if(N>=5000)
           return 1;
        vector<vector<double>>t(N+1,vector<double>(N+1,0));
        
        return solve(N,N,t);
    }
};