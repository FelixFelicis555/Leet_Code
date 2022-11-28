class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,vector<int>>m;
        set<int>s;
        int n=matches.size();
        for(int i=0;i<n;i++)
        {
            m[matches[i][1]].push_back(matches[i][0]);
            s.insert(matches[i][0]);
        
        } 
        vector<int>v;
        vector<int>v1;
        for( auto & [key,val] :m )
        {
            if(val.size()==1)
            {
                v.push_back(key);
            }    
        }
        for(auto x: s)
        {
           if(m.find(x)==m.end())
               v1.push_back(x);
        }
        vector<vector<int>>ans;
        ans.push_back(v1);
        ans.push_back(v);
        return ans;
        
        
        
    }
};