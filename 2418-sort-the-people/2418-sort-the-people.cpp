class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
       vector<int>ids(names.size());
       iota(begin(ids),end(ids),0);
        vector<string>res;
        sort(begin(ids),end(ids),[&](int i,int j){
            return heights[i]>heights[j];
        });
        transform(begin(ids),end(ids),back_inserter(res),[&](int i){
            return names[i];
        });
        return res;
    }
};