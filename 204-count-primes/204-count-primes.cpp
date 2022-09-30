class Solution {
public:
    int countPrimes(int n) {
        int ans=0;
        vector<bool>seen(n,false);
        for(int num=2;num<n;num++)
        {
            if(seen[num])
                continue;
            ans++;
            for(long mult=(long)num*num;mult<n;mult+=num)
            {
                seen[mult]=true;
            }    
        }
        return ans;
    }
};