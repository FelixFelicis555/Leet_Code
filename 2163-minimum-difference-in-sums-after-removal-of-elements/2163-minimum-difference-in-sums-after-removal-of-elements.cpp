class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
       int n=nums.size();
        priority_queue<int>maxh;
        priority_queue<int,vector<int>,greater<int>>minh;
        int n1=n/3;
        vector<long long>left(n,0);
        vector<long long>right(n,0);
        long long s=0;
        for(int i=0;i<n;i++)
        {
            int x=nums[i];
            s+=x;
            maxh.push(x);
            if(maxh.size()>n1)
            {
                int v=maxh.top();
                maxh.pop();
                s-=v;
            }
            left[i]=s;
        }
        s=0;
        for(int i=n-1;i>=0;i--)
        {
            int x=nums[i];
            s+=x;
            minh.push(x);
            if(minh.size()>n1)
            {
                int v=minh.top();
                minh.pop();
                s-=v;
            }
            right[i]=s;
        }
         long long ans=LLONG_MAX;
        for(int i=n1-1;i<2*n1;i++){
            ans=min(ans, left[i]-right[i+1]);
        }
        return ans;
        
    }
};