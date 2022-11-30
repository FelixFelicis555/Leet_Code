class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>m;
        for(auto x:arr)
            m[x]++;
        unordered_set<int>s;
        for(auto i:m)
        {
            if(s.find(i.second)!=s.end())
                return false;
            else
                s.insert(i.second);
        }
        return true;
    }
};