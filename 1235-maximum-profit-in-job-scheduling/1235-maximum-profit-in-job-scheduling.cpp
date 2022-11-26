class Solution {
public:

    int n;
 vector<array<int,3>>events;

    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        for(int i=0;i<n;i++)
            events.push_back({startTime[i],endTime[i],profit[i]});
        sort(events.begin(),events.end());
        vector<int> dp(n, -1);
        function<int(int,int)> dfs = [&](int idx, int end) {
            // reached all events
            if (idx == n) return 0;
            // current start time < previous end time
            // cannot take it -> move to the next one
            if (events[idx][0] < end) return dfs(idx + 1, end);
            // calculate before -> return immediately
            if (dp[idx] != -1) return dp[idx];
            // so we only have two choices left, we either
            return dp[idx] = max(
                // choice 1: take this job and move to the next one from this end time
                events[idx][2] + dfs(idx + 1, events[idx][1]),
                // choice 2: not take this job and move to the next one
                dfs(idx + 1, end)
            );
        };
        return dfs(0, 0);
    }
};