class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       vector<vector<int>>merged;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++)
        {
            if(merged.empty() || merged.back()[1]<intervals[i][0])
            {
                vector<int>v={intervals[i][0],intervals[i][1]};
                merged.push_back(v);
            }
            else
            {
                merged.back()[1]=max(merged.back()[1],intervals[i][1]);
            }
        }
        return merged;
    }
};