class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int res=0;
        for(auto &s:strs)
        {
            if(all_of(s.begin(),s.end(),[](const auto ch){return isdigit(ch);}))
               {
                   res=max(res,stoi(s));
               }
               else
               {
                   res=max(res,(int)s.size());
               }
        }
               return res;
    }
};