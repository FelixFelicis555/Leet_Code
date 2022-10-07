class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>>mp;
        for(auto path:paths)
        {
            stringstream ss(path);
            string dir;
            string file;
            getline(ss,dir,' ');
            while(getline(ss,file,' '))
            {
                string content=file.substr(file.find('(')+1,file.find(')')-file.find('(')-1);
                string name=dir+'/'+file.substr(0,file.find('('));
                mp[content].push_back(name);
            }
        } 
        vector<vector<string>>ans;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second.size()>1)
            {
                ans.push_back(it->second);
            }
        }
        return ans;
    }
};