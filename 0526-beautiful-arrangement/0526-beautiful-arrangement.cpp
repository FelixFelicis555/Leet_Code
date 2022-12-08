class Solution {
public:
    int ans=0;
    int bitmask;
     void solve(int ind, vector<int>&v, int n){
        if(ind>n){
            ans++;
            return;
        }
        for(int i=1;i<=n;i++){
            if(!(bitmask&(1<<i)) && (ind%i==0 || i%ind==0)){
                bitmask|=(1<<i);
                solve(ind+1,v,n);
                bitmask &= ~(1<<i);
            }
        }
    }
    int countArrangement(int n) {
       vector<int>v;
        bitmask=0;
        solve(1,v,n);
        return ans;
    }
};