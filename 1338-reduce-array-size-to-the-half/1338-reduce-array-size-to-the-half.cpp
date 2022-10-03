class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        map<int,int>mp;
        for(auto x:arr)
        {
            mp[x]++;
        } 
        priority_queue<int>pq;
        for(auto it:mp)
        {
            pq.push(it.second);
        } 
        int c=0;
        int k=n;
        while(!pq.empty())
        {
            int x=pq.top();
            c++;
            pq.pop();
            n-=x;
            if(n<=k/2)
                return c;
        } 
        return c;
    }
};