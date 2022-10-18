class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
       vector<pair<int,string>>v;
        int n=names.size();
        vector<string>res;
        for(int i=0;i<n;i++)
        {
            v.push_back({heights[i],names[i]});
        }
        sort(v.begin(),v.end(),greater<>());
        for(auto it:v)
        {
            res.push_back(it.second);
        }
        return res; 
    }
};