class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        vector<vector<int>>arr(stations);
        int n=arr.size();
        int start=startFuel;
        if(n==0)
        {
            if(target<=start)
                return 0;
            return -1;
        }
        int ans=0;
        int loc=0 ; // starting-point
            priority_queue<int>pq; // fuel of stations crossed till now
        for(auto x: arr)
        {
            int dis=x[0];
            int f=x[1];
            start-=(dis-loc);
            while(!pq.empty() && start<0)
            {
                start+=pq.top();
                pq.pop();
                ans++;
            }
            if(start<0)
                return -1;
            pq.push(f);
            loc=dis; // new starting point
        }
        start-=(target-loc);
        while(!pq.empty() && start<0)
        {
            start+=pq.top();
            pq.pop();
            ans++;
        }
        if(start<0)
         return -1;
        return ans;
    }
};