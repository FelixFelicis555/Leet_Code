class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>m;
        for(string s:strs)
        {
            string s2=s;
            sort(s2.begin(),s2.end());
            m[s2].push_back(s);
        }
        vector<vector<string>>res;
        for(auto e:m)
        {
            res.push_back(e.second);
        }
        return res;
    }
};